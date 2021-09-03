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

  socklen_t saddrLen;

  int retval;

  char buf[BUFSIZ];

  /* create socket */
  fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  if (fd == -1)
    {
      fprintf (stderr, "Couldn't create socket\n");
      exit (EXIT_FAILURE);
    }

  /* sendto/recvfrom */
  saddr.sin_family = AF_INET;

  saddr.sin_port = htons (PORT);

  saddr.sin_addr.s_addr = inet_addr (IP);

  strcpy (buf, "Hello World form client\n");

  sendto (fd, buf, strlen (buf), 0, (struct sockaddr *)&saddr, sizeof (saddr));

  recvfrom (fd, buf, BUFSIZ, 0, (struct sockaddr *)&saddr, &saddrLen);

  printf ("data : %s\n", buf);

  return EXIT_SUCCESS;
}