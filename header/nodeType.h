/*
 * nodeType.h
 *
 *  Created on: 13/11/2016
 *      Author: dlynazmi
 */

#ifndef NODETYPE_H_
#define NODETYPE_H_

template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};



#endif /* NODETYPE_H_ */
