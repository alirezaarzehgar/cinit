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
  fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  if (fd == -1)
    {
      fprintf (stderr, "Couldn't create socket\n");
      exit (EXIT_FAILURE);
    }

  /* binding */
  saddr.sin_family = AF_INET;

  saddr.sin_port = htons (PORT);

  saddr.sin_addr.s_addr = inet_addr (IP);

  retval = bind (fd, (struct sockaddr *)&saddr, sizeof (saddr));

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't bind on network\n");
      exit (EXIT_FAILURE);
    }

  /* loop */
  while (1)
    {
      int counter = 0;

      struct sockaddr_in caddr;

      socklen_t caddrLen = sizeof (saddr);

      char buf[BUFSIZ];

      while (counter <= 0)
        {
          counter = recvfrom (fd, buf, BUFSIZ, 0, (struct sockaddr *)&caddr,
                              &caddrLen);
        }

      printf ("data : %s\n", buf);

      strcpy (buf, "Hello World from server\n");

      sendto (fd, buf, strlen (buf), 0, (struct sockaddr *)&caddr, caddrLen);
    }

  return EXIT_SUCCESS;
}