/* Generated By:JavaCC: Do not edit this line. InfixParserTokenManager.java */

public class InfixParserTokenManager implements InfixParserConstants
{
  public  java.io.PrintStream debugStream = System.out;
  public  void setDebugStream(java.io.PrintStream ds) { debugStream = ds; }
private final int jjStopStringLiteralDfa_0(int pos, long active0)
{
   switch (pos)
   {
      case 0:
         if ((active0 & 0x20480L) != 0L)
         {
            jjmatchedKind = 27;
            return 79;
         }
         if ((active0 & 0x200L) != 0L)
         {
            jjmatchedKind = 27;
            return 4;
         }
         return -1;
      case 1:
         if ((active0 & 0x20600L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 1;
            return 79;
         }
         if ((active0 & 0x80L) != 0L)
            return 79;
         return -1;
      case 2:
         if ((active0 & 0x20000L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 2;
            return 79;
         }
         if ((active0 & 0x600L) != 0L)
            return 79;
         return -1;
      case 3:
         if ((active0 & 0x20000L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 3;
            return 79;
         }
         return -1;
      case 4:
         if ((active0 & 0x20000L) != 0L)
         {
            jjmatchedKind = 27;
            jjmatchedPos = 4;
            return 79;
         }
         return -1;
      default :
         return -1;
   }
}
private final int jjStartNfa_0(int pos, long active0)
{
   return jjMoveNfa_0(jjStopStringLiteralDfa_0(pos, active0), pos + 1);
}
private final int jjStopAtPos(int pos, int kind)
{
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   return pos + 1;
}
private final int jjStartNfaWithStates_0(int pos, int kind, int state)
{
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) { return pos + 1; }
   return jjMoveNfa_0(state, pos + 1);
}
private final int jjMoveStringLiteralDfa0_0()
{
   switch(curChar)
   {
      case 40:
         return jjStopAtPos(0, 29);
      case 41:
         return jjStopAtPos(0, 30);
      case 42:
         return jjStopAtPos(0, 15);
      case 43:
         return jjStopAtPos(0, 13);
      case 44:
         return jjStopAtPos(0, 32);
      case 45:
         return jjStopAtPos(0, 14);
      case 60:
         jjmatchedKind = 22;
         return jjMoveStringLiteralDfa1_0(0x100000L);
      case 61:
         return jjStopAtPos(0, 18);
      case 62:
         jjmatchedKind = 21;
         return jjMoveStringLiteralDfa1_0(0x80000L);
      case 94:
         return jjStopAtPos(0, 16);
      case 100:
         return jjMoveStringLiteralDfa1_0(0x20000L);
      case 105:
         return jjMoveStringLiteralDfa1_0(0x80L);
      case 109:
         return jjMoveStringLiteralDfa1_0(0x400L);
      case 115:
         return jjMoveStringLiteralDfa1_0(0x200L);
      default :
         return jjMoveNfa_0(2, 0);
   }
}
private final int jjMoveStringLiteralDfa1_0(long active0)
{
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(0, active0);
      return 1;
   }
   switch(curChar)
   {
      case 61:
         if ((active0 & 0x80000L) != 0L)
            return jjStopAtPos(1, 19);
         else if ((active0 & 0x100000L) != 0L)
            return jjStopAtPos(1, 20);
         break;
      case 97:
         return jjMoveStringLiteralDfa2_0(active0, 0x400L);
      case 102:
         if ((active0 & 0x80L) != 0L)
            return jjStartNfaWithStates_0(1, 7, 79);
         break;
      case 105:
         return jjMoveStringLiteralDfa2_0(active0, 0x20000L);
      case 117:
         return jjMoveStringLiteralDfa2_0(active0, 0x200L);
      default :
         break;
   }
   return jjStartNfa_0(0, active0);
}
private final int jjMoveStringLiteralDfa2_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(0, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(1, active0);
      return 2;
   }
   switch(curChar)
   {
      case 109:
         if ((active0 & 0x200L) != 0L)
            return jjStartNfaWithStates_0(2, 9, 79);
         break;
      case 118:
         return jjMoveStringLiteralDfa3_0(active0, 0x20000L);
      case 120:
         if ((active0 & 0x400L) != 0L)
            return jjStartNfaWithStates_0(2, 10, 79);
         break;
      default :
         break;
   }
   return jjStartNfa_0(1, active0);
}
private final int jjMoveStringLiteralDfa3_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(1, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(2, active0);
      return 3;
   }
   switch(curChar)
   {
      case 105:
         return jjMoveStringLiteralDfa4_0(active0, 0x20000L);
      default :
         break;
   }
   return jjStartNfa_0(2, active0);
}
private final int jjMoveStringLiteralDfa4_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(2, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(3, active0);
      return 4;
   }
   switch(curChar)
   {
      case 100:
         return jjMoveStringLiteralDfa5_0(active0, 0x20000L);
      default :
         break;
   }
   return jjStartNfa_0(3, active0);
}
private final int jjMoveStringLiteralDfa5_0(long old0, long active0)
{
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(3, old0); 
   try { curChar = input_stream.readChar(); }
   catch(java.io.IOException e) {
      jjStopStringLiteralDfa_0(4, active0);
      return 5;
   }
   switch(curChar)
   {
      case 101:
         if ((active0 & 0x20000L) != 0L)
            return jjStartNfaWithStates_0(5, 17, 79);
         break;
      default :
         break;
   }
   return jjStartNfa_0(4, active0);
}
private final void jjCheckNAdd(int state)
{
   if (jjrounds[state] != jjround)
   {
      jjstateSet[jjnewStateCnt++] = state;
      jjrounds[state] = jjround;
   }
}
private final void jjAddStates(int start, int end)
{
   do {
      jjstateSet[jjnewStateCnt++] = jjnextStates[start];
   } while (start++ != end);
}
private final void jjCheckNAddTwoStates(int state1, int state2)
{
   jjCheckNAdd(state1);
   jjCheckNAdd(state2);
}
private final void jjCheckNAddStates(int start, int end)
{
   do {
      jjCheckNAdd(jjnextStates[start]);
   } while (start++ != end);
}
private final void jjCheckNAddStates(int start)
{
   jjCheckNAdd(jjnextStates[start]);
   jjCheckNAdd(jjnextStates[start + 1]);
}
private final int jjMoveNfa_0(int startState, int curPos)
{
   int[] nextStates;
   int startsAt = 0;
   jjnewStateCnt = 79;
   int i = 1;
   jjstateSet[0] = startState;
   int j, kind = 0x7fffffff;
   for (;;)
   {
      if (++jjround == 0x7fffffff)
         ReInitRounds();
      if (curChar < 64)
      {
         long l = 1L << curChar;
         MatchLoop: do
         {
            switch(jjstateSet[--i])
            {
               case 4:
               case 23:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  jjCheckNAddTwoStates(23, 24);
                  break;
               case 79:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  jjCheckNAddTwoStates(23, 24);
                  break;
               case 2:
                  if ((0x3ff000000000000L & l) != 0L)
                  {
                     if (kind > 28)
                        kind = 28;
                     jjCheckNAddStates(0, 3);
                  }
                  else if (curChar == 46)
                     jjCheckNAdd(36);
                  else if (curChar == 34)
                     jjstateSet[jjnewStateCnt++] = 19;
                  break;
               case 11:
                  if (curChar != 58)
                     break;
                  if (kind > 8)
                     kind = 8;
                  jjCheckNAdd(12);
                  break;
               case 12:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 8)
                     kind = 8;
                  jjCheckNAdd(12);
                  break;
               case 18:
                  if (curChar == 34)
                     jjstateSet[jjnewStateCnt++] = 19;
                  break;
               case 20:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjAddStates(4, 5);
                  break;
               case 21:
                  if (curChar == 34 && kind > 26)
                     kind = 26;
                  break;
               case 25:
                  if (curChar == 32)
                     jjCheckNAddStates(6, 8);
                  break;
               case 26:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddStates(9, 12);
                  break;
               case 27:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(27, 28);
                  break;
               case 28:
                  if (curChar == 44)
                     jjCheckNAddStates(13, 15);
                  break;
               case 29:
                  if (curChar == 32)
                     jjCheckNAddStates(13, 15);
                  break;
               case 31:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(31, 28);
                  break;
               case 32:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(32, 33);
                  break;
               case 34:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(34, 33);
                  break;
               case 35:
                  if (curChar == 46)
                     jjCheckNAdd(36);
                  break;
               case 36:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAdd(36);
                  break;
               case 37:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAddStates(0, 3);
                  break;
               case 38:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAddTwoStates(38, 39);
                  break;
               case 39:
                  if (curChar != 46)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAdd(40);
                  break;
               case 40:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 28)
                     kind = 28;
                  jjCheckNAdd(40);
                  break;
               case 41:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(41, 35);
                  break;
               case 46:
                  if (curChar == 48 && kind > 5)
                     kind = 5;
                  break;
               case 47:
                  if (curChar == 49)
                     jjstateSet[jjnewStateCnt++] = 46;
                  break;
               case 53:
                  if (curChar != 58)
                     break;
                  if (kind > 11)
                     kind = 11;
                  jjCheckNAdd(54);
                  break;
               case 54:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 11)
                     kind = 11;
                  jjCheckNAdd(54);
                  break;
               case 58:
                  if (curChar == 58)
                     jjCheckNAddTwoStates(59, 60);
                  break;
               case 59:
                  if ((0x3ff000000000000L & l) != 0L)
                     jjCheckNAddTwoStates(59, 60);
                  break;
               case 60:
                  if (curChar != 58)
                     break;
                  if (kind > 12)
                     kind = 12;
                  jjCheckNAdd(61);
                  break;
               case 61:
                  if ((0x3ff000000000000L & l) == 0L)
                     break;
                  if (kind > 12)
                     kind = 12;
                  jjCheckNAdd(61);
                  break;
               case 71:
                  if (curChar == 58)
                     jjCheckNAddTwoStates(72, 73);
                  break;
               case 72:
                  if ((0x7fffc0d000000000L & l) != 0L)
                     jjCheckNAddTwoStates(72, 73);
                  break;
               case 73:
                  if (curChar == 58)
                     jjCheckNAdd(74);
                  break;
               case 74:
                  if ((0x7fffc4d000000000L & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  jjCheckNAdd(74);
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else if (curChar < 128)
      {
         long l = 1L << (curChar & 077);
         MatchLoop: do
         {
            switch(jjstateSet[--i])
            {
               case 4:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                  {
                     if (kind > 27)
                        kind = 27;
                     jjCheckNAddTwoStates(23, 24);
                  }
                  else if (curChar == 91)
                     jjAddStates(6, 8);
                  if (curChar == 105)
                     jjCheckNAdd(3);
                  break;
               case 79:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                  {
                     if (kind > 27)
                        kind = 27;
                     jjCheckNAddTwoStates(23, 24);
                  }
                  else if (curChar == 91)
                     jjAddStates(6, 8);
                  break;
               case 2:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                  {
                     if (kind > 27)
                        kind = 27;
                     jjCheckNAddTwoStates(23, 24);
                  }
                  if (curChar == 120)
                     jjAddStates(16, 17);
                  else if (curChar == 97)
                     jjAddStates(18, 19);
                  else if (curChar == 108)
                     jjAddStates(20, 22);
                  else if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 16;
                  else if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 9;
                  else if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 7;
                  else if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 4;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 1;
                  break;
               case 0:
                  if (curChar == 112 && kind > 5)
                     kind = 5;
                  break;
               case 1:
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 0;
                  break;
               case 3:
                  if (curChar == 110 && kind > 6)
                     kind = 6;
                  break;
               case 5:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 4;
                  break;
               case 6:
                  if (curChar == 115 && kind > 6)
                     kind = 6;
                  break;
               case 7:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 6;
                  break;
               case 8:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 7;
                  break;
               case 9:
                  if (curChar == 97)
                     jjCheckNAdd(3);
                  break;
               case 10:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 9;
                  break;
               case 12:
                  if ((0x7fffffe2ffffffeL & l) == 0L)
                     break;
                  if (kind > 8)
                     kind = 8;
                  jjstateSet[jjnewStateCnt++] = 12;
                  break;
               case 13:
                  if (curChar == 70)
                     jjstateSet[jjnewStateCnt++] = 11;
                  break;
               case 14:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 13;
                  break;
               case 15:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 14;
                  break;
               case 16:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 15;
                  break;
               case 17:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 16;
                  break;
               case 19:
               case 20:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                     jjCheckNAddTwoStates(20, 21);
                  break;
               case 22:
                  if ((0x7fffffe07fffffeL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  jjCheckNAddTwoStates(23, 24);
                  break;
               case 23:
                  if ((0x7fffffe07fffffeL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  jjCheckNAddTwoStates(23, 24);
                  break;
               case 24:
                  if (curChar == 91)
                     jjAddStates(6, 8);
                  break;
               case 30:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                     jjCheckNAddStates(23, 26);
                  break;
               case 31:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                     jjCheckNAddTwoStates(31, 28);
                  break;
               case 32:
                  if ((0x7fffffe07fffffeL & l) != 0L)
                     jjCheckNAddTwoStates(32, 33);
                  break;
               case 33:
                  if (curChar == 93 && kind > 27)
                     kind = 27;
                  break;
               case 42:
                  if (curChar == 108)
                     jjAddStates(20, 22);
                  break;
               case 43:
                  if (curChar == 110 && kind > 5)
                     kind = 5;
                  break;
               case 44:
                  if (curChar == 103 && kind > 5)
                     kind = 5;
                  break;
               case 45:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 44;
                  break;
               case 48:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 47;
                  break;
               case 49:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 48;
                  break;
               case 50:
                  if (curChar == 97)
                     jjAddStates(18, 19);
                  break;
               case 51:
                  if (curChar == 115 && kind > 5)
                     kind = 5;
                  break;
               case 52:
                  if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 51;
                  break;
               case 55:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 53;
                  break;
               case 56:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 55;
                  break;
               case 57:
                  if (curChar == 120)
                     jjAddStates(16, 17);
                  break;
               case 59:
                  if ((0x7fffffe2ffffffeL & l) != 0L)
                     jjAddStates(27, 28);
                  break;
               case 61:
                  if ((0x7fffffe2ffffffeL & l) == 0L)
                     break;
                  if (kind > 12)
                     kind = 12;
                  jjstateSet[jjnewStateCnt++] = 61;
                  break;
               case 62:
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 58;
                  break;
               case 63:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 62;
                  break;
               case 64:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 63;
                  break;
               case 65:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 64;
                  break;
               case 66:
                  if (curChar == 73)
                     jjstateSet[jjnewStateCnt++] = 65;
                  break;
               case 67:
                  if (curChar == 104)
                     jjstateSet[jjnewStateCnt++] = 66;
                  break;
               case 68:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 67;
                  break;
               case 69:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 68;
                  break;
               case 70:
                  if (curChar == 80)
                     jjstateSet[jjnewStateCnt++] = 69;
                  break;
               case 72:
                  if ((0x7fffffe2fffffffL & l) != 0L)
                     jjAddStates(29, 30);
                  break;
               case 74:
                  if ((0x2ffffffe2fffffffL & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  jjstateSet[jjnewStateCnt++] = 74;
                  break;
               case 75:
                  if (curChar == 104)
                     jjstateSet[jjnewStateCnt++] = 71;
                  break;
               case 76:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 75;
                  break;
               case 77:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 76;
                  break;
               case 78:
                  if (curChar == 80)
                     jjstateSet[jjnewStateCnt++] = 77;
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else
      {
         int i2 = (curChar & 0xff) >> 6;
         long l2 = 1L << (curChar & 077);
         MatchLoop: do
         {
            switch(jjstateSet[--i])
            {
               default : break;
            }
         } while(i != startsAt);
      }
      if (kind != 0x7fffffff)
      {
         jjmatchedKind = kind;
         jjmatchedPos = curPos;
         kind = 0x7fffffff;
      }
      ++curPos;
      if ((i = jjnewStateCnt) == (startsAt = 79 - (jjnewStateCnt = startsAt)))
         return curPos;
      try { curChar = input_stream.readChar(); }
      catch(java.io.IOException e) { return curPos; }
   }
}
static final int[] jjnextStates = {
   38, 39, 41, 35, 20, 21, 25, 26, 30, 27, 28, 34, 33, 29, 26, 30, 
   70, 78, 52, 56, 43, 45, 49, 31, 28, 32, 33, 59, 60, 72, 73, 
};
public static final String[] jjstrLiteralImages = {
"", null, null, null, null, null, null, "\151\146", null, "\163\165\155", 
"\155\141\170", null, null, "\53", "\55", "\52", "\136", "\144\151\166\151\144\145", "\75", 
"\76\75", "\74\75", "\76", "\74", null, null, null, null, null, null, "\50", "\51", null, 
"\54", };
public static final String[] lexStateNames = {
   "DEFAULT", 
};
static final long[] jjtoToken = {
   0x1fc7fffe1L, 
};
static final long[] jjtoSkip = {
   0x1eL, 
};
protected SimpleCharStream input_stream;
private final int[] jjrounds = new int[79];
private final int[] jjstateSet = new int[158];
protected char curChar;
public InfixParserTokenManager(SimpleCharStream stream)
{
   if (SimpleCharStream.staticFlag)
      throw new Error("ERROR: Cannot use a static CharStream class with a non-static lexical analyzer.");
   input_stream = stream;
}
public InfixParserTokenManager(SimpleCharStream stream, int lexState)
{
   this(stream);
   SwitchTo(lexState);
}
public void ReInit(SimpleCharStream stream)
{
   jjmatchedPos = jjnewStateCnt = 0;
   curLexState = defaultLexState;
   input_stream = stream;
   ReInitRounds();
}
private final void ReInitRounds()
{
   int i;
   jjround = 0x80000001;
   for (i = 79; i-- > 0;)
      jjrounds[i] = 0x80000000;
}
public void ReInit(SimpleCharStream stream, int lexState)
{
   ReInit(stream);
   SwitchTo(lexState);
}
public void SwitchTo(int lexState)
{
   if (lexState >= 1 || lexState < 0)
      throw new TokenMgrError("Error: Ignoring invalid lexical state : " + lexState + ". State unchanged.", TokenMgrError.INVALID_LEXICAL_STATE);
   else
      curLexState = lexState;
}

protected Token jjFillToken()
{
   Token t = Token.newToken(jjmatchedKind);
   t.kind = jjmatchedKind;
   String im = jjstrLiteralImages[jjmatchedKind];
   t.image = (im == null) ? input_stream.GetImage() : im;
   t.beginLine = input_stream.getBeginLine();
   t.beginColumn = input_stream.getBeginColumn();
   t.endLine = input_stream.getEndLine();
   t.endColumn = input_stream.getEndColumn();
   return t;
}

int curLexState = 0;
int defaultLexState = 0;
int jjnewStateCnt;
int jjround;
int jjmatchedPos;
int jjmatchedKind;

public Token getNextToken() 
{
  int kind;
  Token specialToken = null;
  Token matchedToken;
  int curPos = 0;

  EOFLoop :
  for (;;)
  {   
   try   
   {     
      curChar = input_stream.BeginToken();
   }     
   catch(java.io.IOException e)
   {        
      jjmatchedKind = 0;
      matchedToken = jjFillToken();
      return matchedToken;
   }

   try { input_stream.backup(0);
      while (curChar <= 32 && (0x100002600L & (1L << curChar)) != 0L)
         curChar = input_stream.BeginToken();
   }
   catch (java.io.IOException e1) { continue EOFLoop; }
   jjmatchedKind = 0x7fffffff;
   jjmatchedPos = 0;
   curPos = jjMoveStringLiteralDfa0_0();
   if (jjmatchedKind != 0x7fffffff)
   {
      if (jjmatchedPos + 1 < curPos)
         input_stream.backup(curPos - jjmatchedPos - 1);
      if ((jjtoToken[jjmatchedKind >> 6] & (1L << (jjmatchedKind & 077))) != 0L)
      {
         matchedToken = jjFillToken();
         return matchedToken;
      }
      else
      {
         continue EOFLoop;
      }
   }
   int error_line = input_stream.getEndLine();
   int error_column = input_stream.getEndColumn();
   String error_after = null;
   boolean EOFSeen = false;
   try { input_stream.readChar(); input_stream.backup(1); }
   catch (java.io.IOException e1) {
      EOFSeen = true;
      error_after = curPos <= 1 ? "" : input_stream.GetImage();
      if (curChar == '\n' || curChar == '\r') {
         error_line++;
         error_column = 0;
      }
      else
         error_column++;
   }
   if (!EOFSeen) {
      input_stream.backup(1);
      error_after = curPos <= 1 ? "" : input_stream.GetImage();
   }
   throw new TokenMgrError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, TokenMgrError.LEXICAL_ERROR);
  }
}

}