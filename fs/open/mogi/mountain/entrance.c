// room1.c by roger
//加入劍魔轉回仙劍的解謎要素 by Alucard 2009/08
inherit ROOM;
#include <ansi.h>
#include "mountain.msg"
void create () {
set ("short","冰蟾洞口");
set ("long","
看來這裡就是傳說中千年冰蟾的洞穴了。傳說中千年冰蟾甚少外出覓
食除非進食時刻已到，但是每次外出所散發的毒氣必定掀起一場腥風
血雨。因此雖然人人談千年冰蟾為之色變，但其廬山真面目卻幾乎沒
人知道，因為凡是見過他的人不是當場化為膿血便是成了他腹中之物
現在雖然只是在洞口，但其內所衝出之毒氣已經使你感到陣陣頭暈。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"hole",
       "down" : __DIR__"room29",
       "enter" : "/open/gsword/room1/blood1/r1.c",
      ]));
        setup();
}
int valid_leave(object me, string dir)
{
 string three_leaf;
  if(dir=="north" && !present("three_leaf",me)){
 tell_object(me,"想想你的愛人，父母。。。你願意他們見到一灘膿血嗎?\n"); 
  return 0;
                                               }
  if(dir=="north" && present("three_leaf",me)){
 tell_object(me,"你聞著三葉仙蘭所散發的香氣，使你勉強能抗拒毒氣的侵襲\n");
  return 1;
                                              }
  if(dir=="enter" && me->query("highsworder")!=1){
 tell_object(me,"想想你的愛人，父母。。。你願意他們見到一個無主幽魂嗎?\n");
 return 0;
}
  if(dir=="enter" && me->query_temp("quest/return_sha") && me->query_temp("quest/return_sha")>2){
 tell_object(me,"你武功\已廢，再進去實在太危險了，回頭吧!!\n");
 return 0;
}
  if(dir=="enter" && me->query("highsworder")==1){
 tell_object(me,"你憑著身上的魔氣..一步步的走進血魔堡中..\n");
 return 1;
}
  return 1;
}
