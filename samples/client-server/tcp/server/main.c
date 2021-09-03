/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief main file for doing anything
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "common/common.h"

/**
 * @brief endpoint
 *
 * @param argc
 * @param argv
 * @return int
 */
int
main (int argc, char const *argv[])
{
  int fd;

  struct sockaddr_in saddr;

  int retval;

  /* create socket */
  fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (fd == -1)
    {
      fprintf (stderr, "Couldn't create socket\n");
      exit (EXIT_FAILURE);
    }

  /* add options */
  int enable = 1;

  retval = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

  if(retval == -1)
  {
    fprintf(stderr, "Couldn't add options\n");
    exit(EXIT_FAILURE);
  }

  /* binding */
  saddr.sin_family = AF_INET;

  saddr.sin_port = htons (PORT);

  saddr.sin_addr.s_addr = inet_addr (IP);

  retval = bind (fd, (struct sockaddr *)&saddr, sizeof (saddr));

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't bind ip&port\n");
      exit (EXIT_FAILURE);
    }

  /* listening on network */
  retval = listen (fd, 10);

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't listen on network\n");
      exit (EXIT_FAILURE);
    }

  /* main loop */
  while (1)
    {
      int newfd;

      struct sockaddr_in caddr;

      socklen_t caddrLen = sizeof (caddr);

      char buf[BUFSIZ];

      newfd = accept (fd, (struct sockaddr *)&caddr, &caddrLen);

      if (newfd == -1)
        {
          fprintf (stderr, "Couldn't accept new connection\n");
          exit (EXIT_FAILURE);
        }

      strcpy (buf, "Hello world from server\n");

      write (newfd, buf, strlen (buf));

      read (newfd, buf, BUFSIZ);

      printf ("data: %s\n", buf);

      close (newfd);
    }

  return EXIT_SUCCESS;
}