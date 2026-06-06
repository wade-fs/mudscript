// Room: /u/g/guetenr/beggar/room/beg2/clr19.c
inherit ROOM;

void create ()
{
  set ("short", "渭水河畔");
  set ("long", @LONG
渭水潺潺向東流去，澄清的河水，看來特別遼闊。秋高氣爽，萬里晴空
，一碧如洗。沿著河水望去，餘波盪漾。水天一色。長夜漫漫，皎潔明亮的
月光映照在江河之中，江上清風，耳得之而為聲，山間明月，目遇之而成色
。無雲的夜空裏，天上星斗綻露出耀眼的光芒，忽有流星劃過天際，閃亮動
人的尾巴讓黑暗深邃的天空浮上一抹光彩。 
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"clr17.c",
]));

  setup();
}
