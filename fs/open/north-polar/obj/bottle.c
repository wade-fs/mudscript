//改自lotch by frequency

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC + "封神寶瓶" + NOR, ({"god-bottle"}));
        set("long","神話時代流傳下來的古器，以g-catch使用。\n");
        set("unit", "瓶");
        set("weight",500);
        set("no_save",1);
        set("no_drop",1);
        set("no_auc",1);
        set("no_sell",1);
        set("no_sac",1);
        set("no_give",1);
        set("no_get",1);
        set("no_put",1);
        set("no_steal",1);
        setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("catch_enemy","g-catch");

}


int catch_enemy(string str)
{
        object ob;
        int i, exp1 , exp2;

        if(!str)
                return notify_fail("你想封鎖什麼神祇 ?\n");
        str=lower_case(str);
        if(!objectp(ob=present(str,environment(this_player()))))
                return notify_fail("這裡並不存在著這位神祇。\n");
        if(!ob->query("god"))
                return notify_fail("封神寶瓶不屑於封印這種下等生靈。\n");
        if(!ob->is_character())
                return notify_fail("封神寶瓶不屑於封印非生命體。\n");
        if(ob->query("be_used"))
                return notify_fail("封神寶瓶一次只能封印一位神祇。\n");
        if( (int) ob->query("max_kee")/5 < (int) ob->query("kee"))
        {
                this_player()->add("sen",-1);
                return notify_fail("祂的神力仍然太過強大，無法強行封印。\n");
        }
        
        
        message_vision( sprintf(HIG + "$N喃喃唸道：" + HIW + "「" + HIC + "天地無極、乾坤借法。多瑪奇莎拉姆..." + HIW + "」" + HIG + "，瞬間，一道強光由瓶中射向$n。\n" + NOR),this_player(),ob);
        this_player()->start_busy(1);
        exp1= (int)ob->query("combat_exp");
        exp2=(int)this_player()->query("combat_exp");
        if( random(exp2) > random(exp1) )
        {
        message_vision( sprintf(HIY + "$N悶哼一聲，不由自主的化作一道清煙竄入瓶中。\n" + NOR),ob);
        environment(ob)->set_temp("god-die",1);
        destruct(ob);
        this_player()->add("sen",-15);
        this_object()->set("be_used",1);
        return 1;
        }
        message_vision( sprintf(HIR + "$N神的力量驟現，" + HIM + "『" + HIW + "神古忌流" + HIY + "‧" + HIB + "煉破反衝壁" + HIM + "』" + HIR + "將強光能源完全吸收，並立即反攻。\n\n" + NOR),ob);
        this_player()->add("sen",-1);
        ob->receive_curing("kee",1000);
        ob->receive_heal("kee",1000);
        ob->kill_ob(this_player());
        return 1;       
}

