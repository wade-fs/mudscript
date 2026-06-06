inherit ROOM;
void create()
{
  set ("short","狼王殿");
  set ("long",@LONG
一進入這房間 ,便迎面襲來一陣殺氣 .你嘗試著定住心神不被嚇到
 ,抬頭一看 ,便發現一面匾額掛在牆上 ,上面大剌剌地刻著三個字 "狼
王殿 " .而坐在你面前的 ,便是這狼谷的主人-- "狼王 "筤騂 !他那炯
炯有神的雙目 ,便像要將你看穿似的 ,令你無法自己 !
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/master_wolf.c" : 1,
  "/open/badman/npc/wolf03.c" : 1,
]));
  
  set("light_up",1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wolf15.c",
]));

  setup();
}
