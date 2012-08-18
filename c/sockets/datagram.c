1:   /* dgramclnt.c:
2:    *
3:    * Example datagram client:
4:    */
5:   #include <stdio.h>
6:   #include <unistd.h>
7:   #include <stdlib.h>
8:   #include <errno.h>
9:   #include <string.h>
10:  #include <time.h>
11:  #include <sys/types.h>
12:  #include <sys/socket.h>
13:  #include <netinet/in.h>
14:  #include <arpa/inet.h>
15:
16:  /*
17:   * This function reports the error and
18:   * exits back to the shell:
19:   */
20:  static void
21:  bail(const char *on_what) {
22:      fputs(strerror(errno),stderr);
23:      fputs(": ",stderr);
24:      fputs(on_what,stderr);
25:      fputc('\n',stderr);
26:      exit(1);
27:  }
28:
29:  int
30:  main(int argc,char **argv) {
31:      int z;
32:      int x; 
33:      char *srvr_addr = NULL;
34:      struct sockaddr_in adr_srvr;/* AF_INET */
35:      struct sockaddr_in adr;     /* AF_INET */
36:      int len_inet;                /* length  */
37:      int s;                         /* Socket */
38:      char dgram[512];        /* Recv buffer */
39:
40:      /*
41:       * Use a server address from the command
42:       * line, if one has been provided.
43:       * Otherwise, this program will default
44:       * to using the arbitrary address
45:       * 127.0.0.23:
46:       */
47:      if ( argc >= 2 ) {
48:          /* Addr on cmdline: */
49:          srvr_addr = argv[1];
50:      } else {
51:          /* Use default address: */
52:          srvr_addr = "127.0.0.23";
53:      }
54:
55:      /*
56:       * Create a socket address, to use
57:       * to contact the server with: 
58:       */
59:      memset(&adr_srvr,0,sizeof adr_srvr);
60:      adr_srvr.sin_family = AF_INET;
61:      adr_srvr.sin_port = htons(9090);
62:      adr_srvr.sin_addr.s_addr =
63:          inet_addr(srvr_addr);
64:
65:      if ( adr_srvr.sin_addr.s_addr == INADDR_NONE )
66:          bail("bad address.");
67:
68:      len_inet = sizeof adr_srvr;
69:
70:      /*
71:       * Create a UDP socket to use:
72:       */
73:      s = socket(AF_INET,SOCK_DGRAM,0);
74:      if ( s == -1 )
75:          bail("socket()");
76:
77:      for (;;) {
78:          /*
79:           * Prompt user for a date format string:
80:           */
81:          fputs("\nEnter format string: ",stdout);
82:          if ( !fgets(dgram,sizeof dgram,stdin) )
83:              break;                        /* EOF */
84:
85:          z = strlen(dgram);
86:          if ( z > 0 && dgram[—z] == '\n' )
87:              dgram[z] = 0;   /* Stomp out newline */
88:
89:          /*
90:           * Send format string to server:
91:           */
92:          z = sendto(s,   /* Socket to send result */
93:              dgram, /* The datagram result to snd */
94:              strlen(dgram), /* The datagram lngth */
95:              0,               /* Flags: no options */
96:              (struct sockaddr *)&adr_srvr,/* addr */
97:              len_inet);  /* Server address length */
98:          if ( z < 0 )
99:              bail("sendto(2)");
100:
101:         /*
102:          * Test if we asked for a server shutdown:
103:          */
104:         if ( !strcasecmp(dgram,"QUIT") )
105:             break;          /* Yes, we quit too */
106:
107:         /*
108:          * Wait for a response:
109:          */
110:         x = sizeof adr;
111:         z = recvfrom(s,                /* Socket */
112:             dgram,           /* Receiving buffer */
113:             sizeof dgram,   /* Max recv buf size */
114:             0,               /* Flags: no options */
115:             (struct sockaddr *)&adr,     /* Addr */
116:             &x);             /* Addr len, in & out */
117:         if ( z < 0 )
118:             bail("recvfrom(2)");
119:
120:         dgram[z] = 0;          /* null terminate */
121:
122:         /*
123:          * Report Result:
124:          */
125:         printf("Result from %s port %u :\n\t'%s'\n",
126:             inet_ntoa(adr.sin_addr),
127:             (unsigned)ntohs(adr.sin_port),
128:             dgram);
129:     }
130:
131:     /*
132:      * Close the socket and exit:
133:      */
134:     close(s);
135:     putchar('\n');
136:
137:     return 0;
138: }