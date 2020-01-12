#include "disjoint_sets.h"
#include<iostream>
using namespace std;

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets( int numElements ) : s( numElements+1, -1 )
{
    sets = numElements;
}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets( int root1, int root2 )
{
    if(setConnected(root1,root2) == false){
        sets--;
    }
    if( s[ root2 ] < s[ root1 ] ){  // root2 is deeper
        s[ root1 ] = root2;        // Make root2 new root
        
    }
    else{
        if( s[ root1 ] == s[ root2 ] )
            --s[ root1 ];          // Update height if same
        s[ root2 ] = root1;        // Make root1 new root
        
    }

    
}


/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x ) const
{
    if( s[ x ] < 0 )
        return x;
    else
        return find( s[ x ] );
}


/**
 * Perform a find with path compression.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x )
{
    if( s[ x ] < 0 )
        return x;
    else
        return s[ x ] = find( s[ x ] );
}

void DisjSets::print(){
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
bool DisjSets::setConnected(int x,int y){
    if(find(x) == find(y)){
        return true;
    }else {
        return false;
    }
}
bool DisjSets::setConnected(){
    if(sets == 1){
        return true;
    }else{
        return false;
    }
}

