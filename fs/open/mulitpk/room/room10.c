inherit ROOM;

void create ()
{
  set ("short", "狂想之武林大會會場");
  set ("long", @LONG
這裡是狂想空間裡武林大會的會場, 你左右一望, 只見四周已擠滿
了前來看熱鬧的觀眾, 而場地裡已經有許多參加者正在熱身, 個個都一
副勢在必得的樣子

LONG);

  set("light_up", 1);
  set("pkroom", 1);
  set("no_auc", 1);
        set("no_transmit", 1);
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room06",
  "west" : __DIR__"room09.c",
  "east" : __DIR__"room11.c",
]));

  setup();
}
