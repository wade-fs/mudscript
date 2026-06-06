#include <ansi.h>
inherit NPC;
string ask_test();
void create()
{
        set_name(HIW + "第三試煉者" + NOR, ({ "testman"}) );
        set("gender", "男性" );
        set("age", 63);
        set("int", 26);
set("long","傳說中專門鍛鍊仙劍派門人的守護者..你可以問他有關試煉的事。\n");
        set("inquiry",([
        "試煉":(:ask_test:),
        ]));
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);
                set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
   }
string ask_test()
{

tell_object(this_player(),HIW + "第三試驗的目的在於考驗你的武力..\n" + NOR);
 return (HIW + "所以你往北方走去找試煉者吧\n" + NOR);
 
}
