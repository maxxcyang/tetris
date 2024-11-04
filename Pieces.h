/*****************************************************************************************
/* File: Pieces.h
/* Desc: All the Tetris pieces with their respective rotations and displacements for the hotspot
*/

#ifndef _PIECES_
#define _PIECES_


// --------------------------------------------------------------------------------
//									 Pieces
// --------------------------------------------------------------------------------

class Pieces
{
public:

	int GetBlockType		(int pPiece, int pRotation, int pX, int pY);
	int GetXInitialPosition (int pPiece, int pRotation);
	int GetYInitialPosition (int pPiece, int pRotation);
};

#endif // _PIECES_
