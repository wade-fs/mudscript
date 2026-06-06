// Room: /open/main/room/f10.c

inherit ROOM;

void create ()
{
  set ("short", "林中小徑");
  set ("long", @LONG
你身在一片原始森林裡，兩旁盡是高大的林木，微風吹
拂著你的身體，讓你感到非常清涼，暑氣盡消，地上則潮濕
泥濘，在此你聽到西邊傳來隆隆的水聲，看著你沾滿泥巴的
鞋子，心想或許可以到那裡清洗一番。
LONG);

 
 
 
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"road3",
  "south" : __DIR__"room14",
  "west" : __DIR__"road5",
]));

  setup();
}
