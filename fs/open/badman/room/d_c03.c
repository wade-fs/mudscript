inherit ROOM;

void create()
{
  set("short", "密室");
  set("long", "這裡便是通道的盡頭。你在稀微的火光之下看到角落堆積了
相當多的草料。一隻身軀頗為龐大的駱駝正在低著頭吃草。從牠
的嘴邊卻吐出了些許\沙粒，看樣子這就是老頭說的珍貴駱駝了！
");
  
  set("exits", ([ /* sizeof() == 1 */
  "back" : __DIR__"d_c02.c",
]) );

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/t_camel.c" : 1,
]));
  set("light_up",1);

setup();
}
