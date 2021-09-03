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

  char buf[BUFSIZ];

  /* create socket */
  fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (fd == -1)
    {
      fprintf (stderr, "Couldn't create socket\n");
      exit (EXIT_FAILURE);
    }

  /* connecting */
  saddr.sin_family = AF_INET;

  saddr.sin_port = htons (PORT);

  saddr.sin_addr.s_addr = inet_addr (IP);

  retval = connect (fd, (struct sockaddr *)&saddr, sizeof (saddr));

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't connect to server\n");
      exit (EXIT_FAILURE);
    }

  read (fd, buf, BUFSIZ);

  printf ("data: %s\n", buf);

  strcpy (buf, "Hello World from client\n");

  retval = write (fd, buf, strlen (buf));

  return EXIT_SUCCESS;
}