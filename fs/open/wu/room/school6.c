// Room: /u/d/devils/school6.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
你走到正晴武館的東南隅，這裡是武館處罰弟子練功偷懶的地方,地上
擺滿了盛滿水的桶子,被處罰的人需在此處兩手平舉一手一隻大水桶蹲馬步
,如果讓水溢出....嘿嘿...洗好屁股準備挨板子吧!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"school5",
  "north" : __DIR__"school7",
]));
set("objects",([
"/open/wu/npc/trainee3" : 2 ,]));

        set("outdoors", "/open/wu");
        setup();
}
