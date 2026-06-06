inherit ROOM;

void create ()
{
  set ("short", "玄機房");
  set ("long", @LONG
這裡是段譽夫婦所居住的玄機房,段譽雖為一代武林高手,但卻潛心研
究易經八卦及伏羲六十四卦,在這裡可以看到堆積如山的易經書籍,地上還
有一個破掉的龜殼(broken shell)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"aa23",
]));
  set("objects", ([ /* sizeof() == 2 */
"/open/tailong/npc/yan.c":1,
"/open/tailong/npc/duanyu.c":1,
]));
 set("item_desc", ([ /* sizeof() == 1 */
"broken shell" : "
這是一個占卜用的龜殼,不過已經破掉了,不能夠再用....
",
]));

  setup();
  replace_program(ROOM);
}
