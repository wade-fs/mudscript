inherit ROOM;

void create ()
{
  set ("short", "火室圖書館");
  set ("long", @LONG
這裡是存放大自然中有關火之奧秘的書房，記載醫學，算命，文
學，邏輯．．等，你想知道或解決的疑難問題，在這裡似乎都可以找
到滿意的答案，許多儒門弟子也常來此翻閱書籍。由於書籍繁多此地
又分東南西北四堂，以便尋查。
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"r10.c",
  "north" : __DIR__"fire_n.c",
  "south" : __DIR__"fire_s.c",
  "west" : __DIR__"fire_w.c",
  "east" : __DIR__"fire_e.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar2.c" : 1,
]));

  setup();
}
