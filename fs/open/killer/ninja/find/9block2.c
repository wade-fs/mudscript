 // open/killer/ninja/find/9block2.c
 //此為有創意的迷宮，有興趣的巫師可以抄去用
 //利用一間房間作出好像有數十間房間大小的感覺
#include "/open/open.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "九宮迷陣");
  set ("long", @LONG
  
    四周都是相似的環境，每一個地方都是似曾相似
    看來你只能相信你手中的羅盤指示了，
    反正沒犯下錯誤，就不會退回最初點
    
LONG);
 
  set("exits", ([ /* sizeof() == 1   */
      "north" : __DIR__"9block2.c", 
      "east" : __DIR__"9block2.c", 
      "west" : __DIR__"9block2.c", 
      "south" : __DIR__"9block2.c", 
      "northeast" : __DIR__"9block2.c", 
      "northwest" : __DIR__"9block2.c", 
      "southeast" : __DIR__"9block2.c", 
      "southwest" : __DIR__"9block2.c", 
        ]));
  set("no_transmit",2);
  setup();
}

void init()
{
   object me=this_player();
   if (me->query_temp("wrongway"))
   {
     me->move(__DIR__"9block");
     me->delete_temp("9block");
     return ;
   } 
   if(!me->query_temp("9block"))    
   { //代表目前還只是第一步驟
     me->set_temp("9block",1);
     me->set_temp("blockstep",1);
   } 
}

int valid_leave(object me, string dir)
{
   int i;
   
   i=me->query_temp("9block");
   switch(i)
   {
   	case 1:
   	  if (dir != "east")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正確的話，先增加步數，再判斷是否超過了
   	     me->add_temp("blockstep",1);
         if ((me->query_temp("blockstep") <= 2))
   	     	break;
   	     else //代表不小於2，也就是3
   	     { //代表方向正確，且步數已滿，必須先切換方向
   	       me->set_temp("9block",2);
               me->set_temp("blockstep",1);
                break;
             } //因為方向切換了，所以下一次方向就錯誤
          }
        break;
        case 2:
   	  if (dir != "north")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正確的話，先增加步數，再判斷是否超過了
   	     me->add_temp("blockstep",1);
   	     //判斷是否走夠步數
         if ((me->query_temp("blockstep") <= 3))
   	     	break;
   	     else //代表不小於3，也就是4(第三步)
   	     { //代表方向正確，且步數已滿，必須先切換方向
   	       me->set_temp("9block",3);
               me->set_temp("blockstep",1);
                break;
             } //因為方向切換了，所以下一次方向就錯誤
          }
        break;
        case 3:
   	  if (dir != "west")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {
   	     //代表方向正確，且步數已滿，必須先切換方向
   	     me->set_temp("9block",4);
             me->set_temp("blockstep",1);      
          }
        break;
        case 4:
   	  if (dir != "south")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正確的話，先增加步數，再判斷是否超過了
   	     me->add_temp("blockstep",1);
   	     //判斷是否走夠步數
         if ((me->query_temp("blockstep") <= 4))
   	     	break;
   	     else //代表不小於3，也就是4(第三步)
   	     { //代表方向正確，且步數已滿，必須先切換方向
   	       me->set_temp("9block",5);
               me->set_temp("blockstep",1);
                break;
             } //因為方向切換了，所以下一次方向就錯誤
          }
        break;
        case 5:
   	  if (dir != "southeast")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正確的話，先增加步數，再判斷是否超過了
   	     me->add_temp("blockstep",1);
   	     //判斷是否走夠步數
         if ((me->query_temp("blockstep") <= 2))
   	     	break;
   	     else //代表不小於3，也就是4(第三步)
   	     { //代表方向正確，且步數已滿，必須先切換方向
   	       me->set_temp("9block",6);
               me->set_temp("blockstep",1);
                break;
             } //因為方向切換了，所以下一次方向就錯誤
          }
        break;
        case 6:
      if (dir != "northeast")
   	  	me->set_temp("wrongway",1);
   	  else
   	  {//方向正確的話，先增加步數，再判斷是否超過了
   	     me->add_temp("blockstep",1);
   	     //判斷是否走夠步數
         if ((me->query_temp("blockstep") <= 3))
   	     	break;
   	     else //代表不小於3，也就是4(第三步)
   	     { //代表方向正確，且步數已滿，必須先切換方向
   	     
   	       //到這裡已經到達目標......
   	       me->set_temp("firstpart",11);
   message_vision(HIY + "忽然一道光芒出現，讓$N眼睛睜不開來，行囊中似乎多了一點東西\n" + NOR, me);
   	       new("/open/killer/ninja/find/greenring.c")->move(me);
   	       me->move("/open/killer/mon/ghost/room/ghost12.c");
   	       return 0;
               break;
             } //因為方向切換了，所以下一次方向就錯誤
          }
        break;
   
   }   
   return 1;
}
