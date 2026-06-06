// Room: /u/s/sueplan/newplan/area/f9.c
inherit ROOM;

void create ()
{
  set ("short", "雲山山腰");
  set ("long", @LONG
你隨著盤巒山徑登上雲山，滿眼挺拔蒼松高聳入雲，山風徐來松林低吟
，透著幾分灑脫泰然；獨立蒼茫不覺有些悽愴，薄紗般霧氣籠罩四周，釀成
了這揮之不去的沁骨涼意，幾隻蒼鷹自遠處呼嘯而過的和流水的聲音，前方
不遠處彷彿有一個朦朧的不為人知的瀑佈，不知前方是何等的景色，只讓
人腳步加快，想要去窺探其景色。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/beggar/room/beg1/start1.c",
  "north" : __DIR__"f10.c",
]));

  setup();
}
