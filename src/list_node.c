/**
 * Projet AR - Content-Adressable Network
 * Implémentation des primitives de gestion des listes de noeuds
 *
 * @author Ilyas Toumlilt <toumlilt.ilyas@gmail.com>
 * @author Paul  Mabillot <paul.mabilot@etu.upmc.fr>
 *
 * @version 1.0
 */

#include <list_node.h>

/*******************************************************************************
 * Constructors
 ******************************************************************************/
/**
 * Constructeur d'un element list_node
 *
 * @param n le noeud contenu dans l'element ( attention aux NULL )
 * @param next le noeud suivant
 * @return liste_node* l'element alloué.
 */
list_node newListNode()
{
  list_node ret;
  ret.idList[0] = -1;
  ret.size = 0;
  return ret;
}

/*******************************************************************************
 * Destructors
 ******************************************************************************/
/**
 * Destructeur d'une liste de noeuds
 * Free l'element pointé et tous ses successeurs
 *
 * @param ln pointeur sur la list_node à detruire.
 */
/*
void freeListNode(list_node* ln)
{
  if( ln ){
    freeListNode(ln->next);
    free(ln);
  }

  return;
}
*/
/*******************************************************************************
 * Operations
 ******************************************************************************/
/* @todo opti par rapport à la fréquence de parcours */
/**
 * Empile ( au début ) un élement dans la liste
 *
 * @param ln adresse de la liste 
 * @param n le noeud à empiler
 */
void pushNodeToListNode(list_node* ln, int id)
{
  ln->idList[ln->size] = id;
  ln->size++;
  return;
}

/**
 * Dépile un élement ( le premier ) de la liste
 *
 * @param ln adresse de la liste
 * @return le noeud dépilé, NULL si liste vide
 */
int popNodeFromListNode(list_node* ln)
{
  int ret = -1;
  if( ln->size ){
    ret = ln->idList[ln->size];
    ln->size--;
  }
  return ret;
}

/**
 * Dépile l'element d'identidiant id de la liste.
 *
 * @param ln adresse de la liste de noeuds.
 * @param id l'identifiant du noeud à dépiler.
 * @return le noeud dépilé
 */
int popNodeFromListNodeById(list_node* ln, int id)
{
  int ret = -1;
  int i;
  /* phase de recherche */
  for(i=0; i<ln->size; i++){
    if(ln->idList[i] == id){
      ret = id;
      ln->size--;
      break;
    }
  }
  /* phase de décallage */
  for(;i<ln->size; i++){
    ln->idList[i] = ln->idList[i+1];
  }
  return ret;
}

void addNodeToListNode(list_node* ln, int id)
{
  int i;
  for(i=0; i<ln->size; i++)
    if(ln->idList[i] == id)
      return;
  pushNodeToListNode(ln, id);
}

/*******************************************************************************
 * Views
 ******************************************************************************/
void printListNode(list_node ln)
{
  int i;
  printf("[");
  for(i=0; i<ln.size; i++)
    printf("%d,", ln.idList[i]);
  printf("]\n");
  
  return;
}

