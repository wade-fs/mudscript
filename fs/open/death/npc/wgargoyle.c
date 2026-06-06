// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIW + "白無常說道﹕喂﹗新來的﹐你叫什麼名字﹖\n\n" + NOR,
        HIW + "白無常用奇異的眼光盯著你﹐好像要看穿你的一切似的。\n\n" + NOR,
        HIW + "白無常「哼」的一聲﹐從袖中掏出一本像帳冊的東西翻看著。\n\n" + NOR,
        HIW + "白無常閤上冊子﹐說道﹕咦﹖陽壽未盡﹖怎麼可能﹖\n\n" + NOR,
        HIW + "白無常搔了搔頭﹐歎道﹕罷了罷了﹐你走吧。\n\n"
                "一股陰冷的濃霧突然出現﹐很快地包圍了你。\n\n" + NOR,
});

void create()
{
        set_name("白無常", ({ "white gargoyle", "gargoyle" }) );
        set("long",
                "白無常伸著長長的舌頭瞪著你﹐死白的臉上看不出任何喜怒哀樂。\n");
        set("attitude", "peaceful");
        set("random_move",4);
        set("chat_chance", 15);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "白無常發出一陣像呻吟的聲音﹐當他發現你正注視著他的時候﹐瞪了你一眼。\n",
                "白無常把長長的舌頭伸出來﹐緩緩地舔了舔自己又白又長的手指。\n"
        }) );
        set("age", 217);
        set("combat_exp", 20000);
        set("max_gin", 900);
        set("max_kee", 900);
        set("max_sen", 200);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object())
        ||      wizardp(previous_object()) ) return;
        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        if( !ob || !present(ob) ) return;

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else{
/*修正復活後把water跟food加滿 by chan 2002 /08 /19*/
        if(!COMBAT_D->death_effect(ob))
          write_file("/u/b/bss/record/no_death_effect",
            sprintf("%s死了但是沒有扣值!!\n",geteuid(ob)));
                ob->reincarnate();
        DEATHROOM->end_death(ob);
	ob->set("food", ob->max_food_capacity());
    ob->set("water", ob->max_water_capacity());
    if(ob->query("have_get_rest"))
      ob->move("/open/wiz/guilty_room");
    else
        ob->move(REVIVEROOM);
        message("vision",
                "你忽然發現前面多了一個人影﹐不過那人影又好像已經在那裡\n"
                "很久了﹐只是你一直沒發覺。\n", environment(ob), ob);
    }
}
