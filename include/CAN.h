#ifndef __CAN_H_
#define __CAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

typedef struct _point     point;
typedef struct _space     space;
typedef struct _node      node;
typedef struct _list_node list_node;

#define NB_DIRECTIONS 4

/* for directions array */
#define NORTH     0
#define WEST      1
#define SOUTH     2
#define EAST      3
#define NORTHWEST 4
#define NORTHEAST 5
#define SOUTHWEST 6
#define SOUTHEAST 7

#define N 10
#define MAX_DATA 100

/* coord limits */
#define COORD_MIN_X 0
#define COORD_MAX_X 1000
#define COORD_MIN_Y 0
#define COORD_MAX_Y 1000

/* MPI's Process vars */
#define INIT_NODE      0
#define BOOTSTRAP_NODE 1

/*******************************************************************************
 * MPI tags definition
 ******************************************************************************/
/* Insert tags */
#define U_CAN_INSERT     10
#define DONE_INSERT      11
#define FAILED_INSERT    12
#define REQUEST_INSERT   13

/* Neighbor tag */
#define ADD_NEIGHBOR     20
#define RMV_NEIGHBOR     22

/* remove tags */
#define U_CAN_REMOVE     30
#define DONE_REMOVE      31
#define REQUEST_REMOVE   32

#define INFO_REQUEST     90
#define INFO_REQUEST_ACK 91

/* Insert tag */
#define DONE_INSERT_DATA     100
#define REQUEST_INSERT_DATA  101

/* Search tag */
#define DONE_SEARCH_DATA    200
#define FAILED_SEARCH_DATA 	201
#define REQUEST_SEARCH_DATA 202

/* Display tag */
#define WANT_INFO 301
#define GIVE_INFO 302

/* exit tag */
#define END 900



/*******************************************************************************
 * Operations
 ******************************************************************************/
void CANinitialize();
void CANinsert();
int CANhandleMessage();
void CANremove();
void CANend();

int findInsertDirection(point* p, node* trg);
int chooseDirectionRandomly(int direction);

node getNode();
void setNode(node n);

#endif
