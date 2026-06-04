#include <ansi.h>
inherit BULLETIN_BOARD;

#include <ansi.h>
void create()
{
  set_name(HIC + "小希希的梳妝台" + NOR, ({"board"}));
  set("location","/u/c/cccc/workroom.c");
   set("board_id","cccc_b1");
  set("long","
   書要讀 , 女友要顧 , MUD也要玩~~~~~\n
  歡迎大家來灌水....CC..");
    setup();
    set("capacity", 30);
  set("master",({"cccc"}));
}
