#include <weapon.h>
#include <combat.h>
inherit BLADE;
void create()
{
        set_name("受損的妖刀『村雨』",({"bad-evil-mblade","blade"}));
        set_weight(300);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit","把");
set("long","\n『村雨』，刀鋒透明，刀身緋藍，像透明的雨點鑲在緋藍色的骨脊，刀略
長，刀彎處有突出的小尖刃，臨陣殺敵有種莫名快感。\n");
          set("value", 100);
          set("material","blacksteel");
        }
        init_blade(1);
        setup();
}
int query_autoload()
{
if( this_player()->query("evil-mblade")==1 )
return 1;
}
