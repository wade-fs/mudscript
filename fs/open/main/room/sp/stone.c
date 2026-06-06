inherit ITEM;
#include <ansi.h>
int do_dest();

void create()
{
        set_name("女媧石",({"soul stone","stone",}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","
傳說女媧女神與伏羲為兄妹，當盤古將天地劃分為二時，凡界是一片
空蕪蠻荒，洪荒時代水神共工和火神祝融因故吵架而大打出手，水神
打輸羞憤朝西方不周山撞去。頓時山崩地裂出現了一個大窟窿，天倒
下了半邊，地也陷成一道道大裂紋，山林燒起了大火，洪水從地底下
噴湧出來，龍蛇猛獸也四出吞食人民。女媧娘娘目睹人類遭到如此奇
禍苦難，於是殺龍阻洪以火熔漿補天解救了芸芸眾生；此石，就是當
時女媧補天時留下來的七色彩石．

" + HIY + "( blend [種類] 可將煉造之元神融合體內 )
 種類 : force , dodge , move , parry .
\n" + NOR);
        set("value",100);
        set("unit","顆");
        }
        setup();
}

void init()
{
        add_action("do_blend","blend");
}

int do_blend(string arg)
{
object me,ob;
int a,b,c;

        me = this_player();
        ob = this_object();
        a = me->query("refine/common/force");
        b = me->query("refine/common/level");
        c = a*b/10;
        if(!arg)
                return 0;

        if(arg!="force" && arg!="dodge" && arg!="move" && arg!="parry")
                return notify_fail("
( blend [種類] 可將煉造之元神融合體內 )
 種類 : force , dodge , move , parry .");

        if( me->query_temp("refine/common/"+arg) )
                return notify_fail("精練的元神不能重複融合～!\n");
        if( c <= 0 )
                return notify_fail("精煉的元尚不足以增進你的技能～!\n");
        message_vision(HIW + "$N運氣於手掌上的$n，$n發出一陣強烈光芒後～消失了!\n" + NOR,me,ob);
        message_vision(HIW + "$N的"+arg+"增加了"+c+"級!\n" + NOR,me);
        me->set_temp("refine/common/"+arg,1);
        me->add_temp("apply/"+arg,c);
        do_dest();
return 1;
}

int do_dest()
{
        destruct(this_object());
}

