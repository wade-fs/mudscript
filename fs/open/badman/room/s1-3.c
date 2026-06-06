inherit ROOM;
 
void create ()
{
  set ("short", "黑暗的街道");
  set ("long", @LONG
往南邊走，則越來越感到偏僻，這邊雖然是惡人谷，但是這條路卻鮮少有人煙，一股詭異的氣氛慢慢的蔓延了開來。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"s1-2",
  "southdown" : __DIR__"s2",
]));

  setup();
}
