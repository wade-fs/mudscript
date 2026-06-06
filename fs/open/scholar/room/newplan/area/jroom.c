// Room: /u/s/sueplan/newplan/area/jroom.c
inherit ROOM;

void create ()
{
  set ("short", "奇陣八卦-陣心");
  set ("long", @LONG
  
你來到八卦陣的中心﹐看到眼前有一個看似眉目和善的人﹐
不過你細細一看﹐他卻又充滿殺氣﹐看起來四乎對
你並不是有非常大的好感。你看到他身上的穿著
定睛一看才發現他身上竟有六韜奇略一書﹐你這時
才發現﹐原來眼前的這個人竟是有天下第一軍師之稱的
諸葛家後裔﹐諸葛邑昭!!
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/juka_jone" : 1,  
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 2 */
  "leave" : __DIR__"q1.c",
  "south" : __DIR__"room11.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
if(dir=="leave"&&present("juka jone",environment(me)))
  {
return notify_fail("你發覺有人擋在你面, 不讓你過!!!\n");
   }
  return 1;
}
