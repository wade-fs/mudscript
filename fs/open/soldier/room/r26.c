
inherit ROOM;
void create()
{
  set ("short", "大通舖");
  set ("long","
    你一踏進來就踩到軟軟的東西﹐原來是一堆被子﹐這
裡簡直亂的像豬窩一樣﹐在旁邊還睡了幾個人﹐還有聊天
的﹐看起來他們一點也不覺的人客人﹐在你左手邊有房間
蠻特殊的難道是最高階的住在裡面嗎～

 ");
   set("exits", ([
   "west"   : __DIR__"r27.c",
   "north"   : __DIR__"r21.c",
   "east"   : __DIR__"r25.c",
   
  ]));      
  set("light_up", 1);
  setup();
} 

