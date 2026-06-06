inherit ROOM;

void create ()
{
  set ("short", "閨房");
  set ("long", @LONG
哇 !好一間美麗的房間啊 ,有一張舒適的大床位在房間的中央 ,
有一位氣質出眾的少婦 ,正對著掛在牆上的銅鏡 ,梳著她那頭又
黑又亮的長髮 ,看著她那倒映在鏡中的美麗輪廓 ,真是叫人意亂
情迷 ,難以自己 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room29",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/ran.c" : 1,
]));

  setup();
}
