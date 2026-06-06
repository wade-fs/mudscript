inherit ROOM;

void create ()
{
  set ("short", "土室圖書館");
  set ("long", @LONG
這裡是存放大自然中有關土之奧秘的書房，記載醫學，算命，文
學，邏輯．．等，你想知道或解決的疑難問題，在這裡似乎都可以找
到滿意的答案，許多儒門弟子也常來此翻閱書籍。由於書籍繁多此地
又分東南西北四堂，以便尋查。
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"land_n.c",
  "south" : __DIR__"land_s.c",
  "west" : __DIR__"land_w.c",
  "east" : __DIR__"land_e.c",
  "northwest" : __DIR__"r25.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar4.c" : 1,
]));

  setup();
}
