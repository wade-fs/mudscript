//open/fire-hole/f-24.c

#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
inherit ROOM;
void create ()
{
  set ("short", "伙房通道");
  set ("long", @LONG
這裡是少林寺的伙房，為了應付少林寺龐大的人口，到處都是特大
號的煮飯工具。伙房師父忙進忙出的，手上拿著各式的工具開始開伙，
如果少林弟子有需要的話，還可以跟這些師父要吃的。
LONG);

//  set("no_magic", 1); //為了可以攻擊該quest npc 所以開放戰鬥
//  set("no_fight", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"k02.c",
  "east" : __DIR__"k09.c",
  "south" : __DIR__"k11.c",
  "southeast" : __DIR__"k10.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  BONZE_NPC"q1_trainee.c" : 1,
]));

  setup();
}

void init()
{
  object me=this_player();
  int i;
//如果npc不存在 只要呼叫新的npc就好
  i=random(7)+10;
  if (!query("no_reset")) {
    if(sizeof(children(BONZE_NPC"q1_trainee2.c")) < 2) {// && !query("quests/bonze/water/stop")) {
      new(BONZE_NPC"q1_trainee2.c")->move(BONZE_ROOM"k"+i);
      if( wizardp(me) )
      {
        message_vision("現在阿二人在k"+i+"的房間。\n",me);
      }
    }
    i=random(7)+10;
    if(sizeof(children(BONZE_NPC"q1_trainee3.c")) < 2) {// && !query("quests/bonze/water/stop")) {
      new(BONZE_NPC"q1_trainee3.c")->move(BONZE_ROOM"k"+i);
      if( wizardp(me) )
      {
        message_vision("現在阿三人在k"+i+"的房間。\n",me);
      }
    }
  }
}

int start()
{
  object room = this_object();
  call_out("del",1800,room);
  return 1;
}

int del(object room)
{
  object obj,me=this_player();
  int i;
  i=random(7)+10;
  room = this_object();
  room->delete("no_reset");
//如果npc存在 優先做quest mark判斷
  foreach( object npc in children(BONZE_NPC"q1_trainee.c") ) { //不放在reset()裡就只會在被呼叫時才執行 且一次 而非每15分一次
    if( clonep(npc) && npc->query("nickname") ) {
      npc->delete("nickname");
      npc->delete("quests/bonze/water/stop"); //刪除暫停quest的mark
    }
  }
  foreach( object npc in children(BONZE_NPC"k_monk3.c") ) {
    if( clonep(npc) ) {
      npc->delete("quests/bonze/water/stop");
    }
  }
  foreach( object npc in children(BONZE_NPC"q1_trainee2.c") ) {
    if( clonep(npc) && npc->query("nickname") ) {
      npc->delete("nickname");
      npc->delete("quests/bonze/water/stop");
    }
  }
  foreach( object npc in children(BONZE_NPC"q1_trainee3.c") ) {
    if( clonep(npc) && npc->query("nickname") ) {
      npc->delete("nickname");
      npc->delete("quests/bonze/water/stop");
    }
  }
//如果npc不存在 只要呼叫新的npc就好
  if(sizeof(children(BONZE_NPC"q1_trainee2.c")) < 2) {
    new(BONZE_NPC"q1_trainee2.c")->move(BONZE_ROOM"k"+i);
    if( wizardp(me) )
    {
      message_vision("現在阿二人在k"+i+"的房間。\n",me);
    }
  }
  i=random(7)+10;
  if(sizeof(children(BONZE_NPC"q1_trainee3.c")) < 2) {
    new(BONZE_NPC"q1_trainee3.c")->move(BONZE_ROOM"k"+i);
    if( wizardp(me) )
    {
      message_vision("現在阿三人在k"+i+"的房間。\n",me);
    }
  }
  return 1;
}
/*
void reset()
{
  foreach( object npc in children(BONZE_NPC"q1_trainee.c") ) {
    if( clonep(npc) && npc->query("nickname") ) {
      npc->delete("nickname");
      npc->delete("quests/bonze/water/stop"); //刪除暫停quest的mark
    }
  }
  ::reset();
}
*/