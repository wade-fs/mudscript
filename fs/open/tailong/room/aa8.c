inherit ROOM;

void create ()
{
  set ("short", "中庭");
  set ("long", @LONG
這裡是天龍寺前院連接右邊走道的中庭,從這裡向右側走廊向前直走
就是天龍寺的正殿,大雄寶殿,想參拜大佛或有事想找方丈大師從這邊走
就對了,往東似乎是另一條通往外院的走道 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aa6",
  "north" : __DIR__"aa32",
  "east" : __DIR__"aa10",
]));

  setup();
  replace_program(ROOM);
}
