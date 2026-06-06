inherit ROOM;

void create ()
{
  set ("short", "竹林");
  set ("long", @LONG
清新的空氣 ,美麗的竹林 ,還有一隻大熊貓正一邊啃著竹子 ,一
邊好奇的打量著你 ,嘿嘿 ,拿來作東坡肉真是剛剛好 ;有竹有肉
 ,剛好做個不俗的胖子 .你邪惡的想著 .前面有一間小屋 .....
住著誰ㄋ ?

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room37",
  "enter" : __DIR__"room39",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/u/h/houng/mob/bearcat.c" : 1,
]));

  setup();
}
