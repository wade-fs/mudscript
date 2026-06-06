#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

void create()
{
        set_name("宣傳單", ({ "note" }) );

        set("long",

        
        "\n\n進入少林派護山大陣後，您可以使用"HIC"back"NOR"的指令來呼叫，\n一旁的"HIY"驛站"NOR"人員隨即會馬上派馬車送你回到少林寺前。\n\n"

        );

        set("unit", "張");

        set("no_drop", 1);

        set("no_insert", 1);

        setup();
}
