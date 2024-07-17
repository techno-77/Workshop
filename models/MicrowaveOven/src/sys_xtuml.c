/*--------------------------------------------------------------------------
 * File:  sys_xtuml.c
 *
 * Description:
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "MicrowaveOven_sys_types.h"


/* No containers allocated.  */

/*
 * Supply a unique integer ID.
 */
Escher_UniqueID_t
Escher_ID_factory( void )
{
  static Escher_UniqueID_t Escher_ID_factory = 1;
  return Escher_ID_factory++;
}

/*
 * Detect empty handles in expressions.
 */
void * xtUML_detect_empty_handle( void * h, const char * s1, const char * s2 )
{
  if ( 0 == h ) {
    XTUML_EMPTY_HANDLE_TRACE( s1, s2 );
  }
  return h;
}

/*
 * Initialize the node1 instances by linking them into a collection.
 * These containoids will be collected into a null-terminated,
 * singly linked list (slist).
 * This needs to be called during architecture initialization.
 */
void
Escher_SetFactoryInit( const i_t n1_size )
{
  /* Set factory initialization optimized out.  */
}

/*
 * This will copy all of the elements from one set into another
 * set.  If the target set is not empty, it will be cleared
 * before the copy operation occurs freeing any nodes in that set.
 * The new set will use containoids from the free list.
 */
/* Set copy code optimized out.  */

/*
 * Release all nodes in the given set back to the free pool.
 */
/* Set clearing code optimized out.  */

/*
 * Take the union of set1 and set2 and return to_set
 */
/* Set union optimized out.  */

/*
 * Take the intersection of set1 and set2 and return to_set
 */
/* Set intersection optimized out.  */

/*
 * Subtract set2 from set1 and return to_set
 */
/* Set difference optimized out.  */

/*
 * Take the symmetric difference of set1 and set2 and return to_set
 */
/* Set symmetric difference optimized out.  */

/*
 * Insert a single element into the set in no particular order.
 * The element is a data item.  A container node will be allocated
 * to link in the element.
 */
/* Set insertion code optimized out.  */

/*
 * Insert a block of objects into the given set in sequence.  Link the
 * data into the supplied containers.
 * Return a pointer to the linked set.
 */
Escher_SetElement_s *
Escher_SetInsertBlock( Escher_SetElement_s * container,
                       const u1_t * instance,
                       const Escher_size_t length,
                       Escher_size_t count )
{
  Escher_SetElement_s * head = ( count > 0 ) ? container : 0;
  while ( count > 0 ) {
    count--;
    container->object = (void *) instance;  /* Link in the object data.     */
    instance = instance + length;           /* Bump to next object image.   */
    /* String together or ground containoids.  */
    container->next = ( count > 0 ) ? container + 1 : 0;
    container++;
  }
  return head;
}

/*
 * Remove an instance from an instance collection.
 */
/* Signature:  void Escher_SetRemoveInstance( pextent, instance, slot, container, pool ) */

/*
 * Insert an instance onto an extent.
 */
/* Signature:  void Escher_SetInsertInstance( pextent, node ) */


/*
 * Remove a data item from the given set.  This requires searching
 * the set for the item, unlinking the item (if found) and returning
 * the pointer to the removed node.  SetRemoveNode is used
 * when some knowledge of the linking mechanism is required (as
 * in extent management).  SetRemoveElement is used whenever
 * possible.
 */
Escher_SetElement_s *
Escher_SetRemoveNode(
  Escher_ObjectSet_s * set,
  const void * const d
)
{
  Escher_SetElement_s * t = set->head; /* Start with first node.           */
  Escher_SetElement_s * t_old = t;
  /* Find node containing data and unlink from list.                 */
  if ( t->object == d ) {        /* Element found at head.           */
    set->head = t->next;         /* Unlink it from the list.         */
  } else {
    do {                         /* Search for data element.         */
      t_old = t;
      t = t->next;
      if ( t == 0 ) { return 0; } /* absent       */
    } while ( t->object != d );
    t_old->next = t->next;      /* Unlink element from the list.     */
  }
  return t;
}

/*
 * This interface is used more often to remove an element.  This is
 * used when maximum anonymity is required.  Escher_SetRemoveNode is
 * used when some knowledge of the linking mechanism is required (as
 * in extent management).
 */
/* Set remove element code optimized out.  */

/*
 * Return a pointer to the found element when the set contains the 
 * given data element.
 */
const void *
Escher_SetContains(
  const Escher_ObjectSet_s * const set,
  const void * const element
)
{
  const Escher_SetElement_s * node = set->head;
  while ( node != 0 ) {
    if ( node->object == element ) { return node; }  /* found  */
    node = node->next;
  }
  if ( 0 == element ) return ( const void * ) 1; /* every set contains null */
  return 0;                                      /* absent */
}

/*
 * Count the elements in the set.  Return that count.
 * This routine counts nodes.
 */
Escher_size_t
Escher_SetCardinality( const Escher_ObjectSet_s * const set )
{
  Escher_size_t result = 0;
  const Escher_SetElement_s * node = set->head;
  while ( node != 0 ) {
    result++;
    node = node->next;
  }
  return result;
}

/*
 * Return true when the left and right set are equivalent.
 * The left set is equal to the right set if and only if
 * the left set contains all elements of the right set AND
 * the right set contains all elements of the left set.
 */
bool
Escher_SetEquality( Escher_ObjectSet_s * const left_set,
                    Escher_ObjectSet_s * const right_set )
{
  bool rc = true;
  /* Assure the right set contains all elements in the left set */
  const Escher_SetElement_s * node = left_set->head;
  while ( 0 != node ) {
    if ( 0 == right_set || !Escher_SetContains( right_set, node->object ) ) {
      rc = false;
      break;
    }
    node = node->next;
  }
  if ( rc ) {
    /* Assure the left set contains all elements in the right set */
    node = right_set->head;
    while ( 0 != node ) {
      if ( 0 == left_set || !Escher_SetContains( left_set, node->object ) ) {
        rc = false;
        break;
      }
      node = node->next;
    }
  }
  return rc;
}

/*
 * Initialize a set variable.
 */
/* Signature:  void Escher_InitSet( Escher_ObjectSet_s * set ) */

/*
 * Get any element (1st) from a collection.
 */
/* Signature:  void * Escher_SetGetAny( Escher_ObjectSet_s * const set ) */

/*
 * Return true if set is empty.
 */
/* Signature:  bool Escher_SetIsEmpty( const Escher_ObjectSet_s * const set ) */

/*
 * Use this method to reset the cursor.
 */
/* Signature:  void Escher_IteratorReset( Escher_Iterator_s * const iterator,
 *                                        Escher_ObjectSet_s * const set )
 */

/*
 * Interate to the next element and return it.
 */
void *
Escher_IteratorNext( Escher_Iterator_s * const iter )
{
  void * element = 0;
  if ( iter->cursor != 0 ) {
    element = iter->cursor->object;
    iter->cursor = iter->cursor->next;
  }
  return element;
}

/*
 * Set memory bytes to value at destination.
 */
void
Escher_memset( void * const dst, const u1_t val, Escher_size_t len )
{
  u1_t * d = (u1_t *) dst;
  while ( len > 0 ) {
    len--;
    *d++ = val;
  }
}

/*
 * Move memory bytes from source to destination.
 */
void
Escher_memmove( void * const dst, const void * const src, Escher_size_t len )
{
  u1_t * s = (u1_t *) src;
  u1_t * d = (u1_t *) dst;
  while ( len > 0 ) {
    len--;
    *d++ = *s++;
  }
}

/*
 * Copy characters and be paranoid about null delimiter.
 */
c_t *
Escher_strcpy( c_t * dst, const c_t * src )
{
  c_t * s = dst;
  if ( ( 0 != src ) && ( 0 != dst ) ) {
    Escher_size_t i = ESCHER_SYS_MAX_STRING_LEN - 1;
    while ( ( i > 0 ) && ( *src != '\0' ) ) {
      --i;
      *dst++ = *src++;
    }
    *dst = '\0';  /* Ensure delimiter.  */
  }
  return s;
}

/*
 * Add two strings.  Allocate a temporary memory variable to return the value.
 */
c_t *
Escher_stradd( const c_t * left, const c_t * right )
{
  Escher_size_t i = ESCHER_SYS_MAX_STRING_LEN - 1;
  c_t * s = Escher_strget();
  c_t * dst = s;
  if ( 0 == left ) left = "";
  if ( 0 == right ) right = "";
  while ( ( i > 0 ) && ( *left != '\0' ) ) {
    --i;
    *dst++ = *left++;
  }
  while ( ( i > 0 ) && ( *right != '\0' ) ) {
    --i;
    *dst++ = *right++;
  }
  *dst = '\0';  /* Ensure delimiter.  */
  return s;
}

/*
 * Compare two strings.
 * Return negative number if s1 < s2.
 * Return zero if s1 == s2.
 * Return postive number if s1 > s2.
 */
c_t
Escher_strcmp( const c_t *p1, const c_t *p2 )
{
  const c_t *s1 = p1;
  const c_t *s2 = p2;
  c_t c1, c2;
  i_t i = ESCHER_SYS_MAX_STRING_LEN;
  do {
    c1 = *s1++;
    c2 = *s2++;
    if ( c1 == 0 ) { break; }
    --i;
  } while ( ( c1 == c2 ) && ( i >= 0 ) );
  return ( c1 - c2 );
}

/*
 * Return a string buffer.  Rotate through a pool.
 */
c_t *
Escher_strget( void )
{
  c_t * r;
  static u1_t i = 0;
  static c_t s[ 32 ][ ESCHER_SYS_MAX_STRING_LEN ];
  i = ( i + 1 ) % 32;
  r = &s[ i ][ 0 ];
  *r = 0;
  return ( r );
}


/* xtUML class info for all of the components (collections, sizes, etc.) */
Escher_Extent_t * const * const domain_class_info[ SYSTEM_DOMAIN_COUNT ] = {
};

/*
 * Create an instance of the class numbered on the input.
 * Return the handle of the created instance.
 */
Escher_iHandle_t
Escher_CreateInstance(
  const Escher_DomainNumber_t domain_num,
  const Escher_ClassNumber_t class_num
)
{
  Escher_SetElement_s * node;
  Escher_iHandle_t instance;
  Escher_Extent_t * dci = *(domain_class_info[ domain_num ] + class_num);
  node = dci->inactive.head;

  if ( 0 == node ) {
    UserObjectPoolEmptyCallout( domain_num, class_num );
  }

  dci->inactive.head = dci->inactive.head->next;
  instance = (Escher_iHandle_t) node->object;
  if ( 0 != dci->initial_state ) {
    instance->current_state = dci->initial_state;
  }
  Escher_SetInsertInstance( &dci->active, node );
  return instance;
}

/*
 * Delete an instance of the class passed and numbered on the input.
 */
void
Escher_DeleteInstance(
  Escher_iHandle_t instance,
  const Escher_DomainNumber_t domain_num,
  const Escher_ClassNumber_t class_num
)
{
  Escher_SetElement_s * node;
  Escher_Extent_t * dci = *(domain_class_info[ domain_num ] + class_num);
  if ( 0 != instance ) {
    node = Escher_SetRemoveNode( &dci->active, instance );
    node->next = dci->inactive.head;
    dci->inactive.head = node;
    /* Initialize storage to zero.  */
    Escher_memset( instance, 0, dci->size );
    if ( ( 0 != dci->size ) && ( 0 != dci->initial_state ) ) {
      instance->current_state = -1; /* 0xff max for error detection */
    }
  }
}

/*
 * Initialize object factory services.
 * Initialize class instance storage free pool (inanimate list)
 * by linking the empty instances into a collection.
 */
void
Escher_ClassFactoryInit(
  const Escher_DomainNumber_t domain_num,
  const Escher_ClassNumber_t class_num )
{
  Escher_Extent_t * dci = *(domain_class_info[ domain_num ] + class_num);
  if ( 0 != dci ) {
  dci->active.head = 0;
  dci->inactive.head = Escher_SetInsertBlock(
    dci->container,
    (const u1_t *) dci->pool,
    dci->size,
    dci->population );
  }
}
/*
 * Following provides the dispatcher loops for the xtUML event queues.
 */

bool Escher_run_flag = true; /* Turn this off to exit dispatch loop(s).  */
