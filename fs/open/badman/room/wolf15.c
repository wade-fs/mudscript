inherit ROOM;
void create()
{
   set ("short","小道");
  set ("long",@LONG
這裡看來是這條道路的盡頭 ,眼前便是一面聳立的山壁 .西方是一
間民房 .從房中散發出來的霸氣和殺氣 ,你不但明瞭了狼隻安靜的原因
 ,也同時知道這其中的人物必不簡單 .
LONG);


  set("outdoors","/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wolf12.c",
  "enter" : __DIR__"wolf16.c",
]));

  setup();
}
