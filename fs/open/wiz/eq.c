inherit ROOM ;

#include <ansi.h>

void create ()
{
    set ("short", "ＥＱ品管工廠");
    set ("long", @LONG
這是管理小組經營的工廠。四面有 Acelan 和 Anmy 等大神的超帥
神像供小組成員天天膜拜。散落的ＥＱ堆了一地，亂七八糟。鐵柱子上
釘了幾塊告示牌。
    告示牌上註明了「 武器製造規則 : help weapon_rule 」
		  「 防具製造規則 : help armor_rule 」

LONG);

    set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"entrance",
      ]));
    set("no_fight", 1);
    set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/robot9-1" : 1,
      ]));
    set("no_magic", 1);

    setup();
    call_other("/obj/board/eq_b", "???");
}








