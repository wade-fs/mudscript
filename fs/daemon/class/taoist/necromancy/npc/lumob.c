#include <ansi.h>
#include <combat.h>

inherit NPC;

#define bell_big 600
#define bell_small 200
#define INVLEVEL 70
#define MANACOST 150
#define INVCOST 30

int special_att();
object room2;

void create()
{
        set_name( "巨靈神", ({ "huge god", "god" }) );
        set( "long", @LONG
他是天兵小頭領，打過不知多少大仗小仗。他是名副其實的巨
人，有一棟樓之高。他手裡的一把輪盤大斧也不之劈下多少妖魔鬼
怪的腦袋。你見了他的頭一映象就是想逃。
LONG    );
        set("attitude", "friendly");
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("max_kee",2500);
      set("kee",2500);
        set("max_force", 2000);
        set("force", 2000);
        set_skill("axe",120);
        set_skill("dodge",100);
        set_skill("fly-steps",70);
        map_skill("dodge","fly-steps");
        set_skill("parry",100);
        set("force_factor",15);
        set("str", 50);
        set("cor", 30);
        set("cps", 25);
        set("chat_chance_combat",45);
        set("chat_msg_combat", ({(: special_att :)}));
        setup();
        carry_object(__DIR__"obj/golden_armor")->wear();
        carry_object(__DIR__"obj/hugeaxe")->wield();
}

void besummon(object who, object room)
{
         int i, bell, pp, mkee;
        object *enemy;
        object me = this_object();

        room2 = room;

        message_vision(HIB"一陣清風吹過﹐走出一個身高十丈的$N。\n$N喝道﹕奉命差遣﹗\n"NOR, me);
        set("combat_exp",2500000);
        set("max_kee",2500);
        set("kee",2500);

        switch( who->query("bellicosity") )
        {
                case 0..bell_small :
                        message_vision(HIW"$N笑道：仙人有令，怎敢不從？\n"NOR, me);
                        break;
                case bell_small+1..bell_big : 
                        message_vision("$N皺眉道：如此小事，也來差遣我﹗\n"NOR, me);
                        break;
                default :
                        message_vision(HIB"$N怒喝：何方妖魔，膽敢妄遣天兵﹗\n", me);
                        kill_ob (who);
                        set_leader (who);
                        return;
        }

        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                enemy[i]->fight_ob(this_object());
                fight_ob(enemy[i]);
        }
        set_leader(who);
        who->add_temp ("invocation", INVCOST);
}

void heart_beat()
{
        object who;

        if (!is_fighting() || !who = query_leader() ) {
             call_out( "leave", 0);
             return;
        }

        if(room2!=environment(who)||!who->is_fighting()) {
             call_out( "leave", 0);
             return;
        }

        ::heart_beat();
}

void leave()
{
        object who;

        message_vision(HIB"$N說道﹕末將奉法主召喚﹐現在已經完成護法任務﹐就此告辭﹗\n一陣清風吹過，$N的身形隨之不見了。\n"NOR, this_object() );

        if( who = query_leader() )
                who->add_temp ( "invocation", -INVCOST);
        destruct(this_object());
}

void unconcious()
{
        object who;

        if( who = query_leader() )
                who->add_temp ("invocation", -INVCOST);
        message_vision (HIB"$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
        destruct(this_object ());
}

// 需要invocation 熟練等級
int needlevel ()
{
        return INVLEVEL;
}

// 耗費的mana
int manacost ()
{
        return MANACOST;
}

// 耗費的招喚點數
int invcost ()
{
        return INVCOST;
}

int special_att ()
{
        object me = this_object();
        object victim, *enemy = query_enemy();
        int damage, i;

        if( !i = sizeof(enemy) )       
                return 0;

        victim = enemy[random(i)];
        message_vision (HIR"只聽$N怒喝一聲" + HIW"「力劈華山」" + HIR "！！\n" +
                  "手中巨靈斧雷霆一般猛劈下來。\n", me);

        switch( random(2) ) {
                
        case 1 :
                damage = 30+(victim->query("max_kee") / 7);
                        
                switch( damage ) {
                case 0..50 :    damage = 100;    break;
                case 51..300 :  damage = 250;   break;
                default :       damage = 400;   break;
                }

                message_vision ("$N不幸被一斧劈中，頓時全身血如泉湧。\n"NOR, victim);
                victim->apply_condition ("bleeding", random (i * i));
                victim->receive_damage ("kee", damage, me);
                COMBAT_D->report_status (victim, 0);
                break;
        default :
                message_vision ("只可惜離$N差了一點，劈到地上。轟的一聲巨響，地皮頓時裂了開來。\n"NOR, victim);
        }
        me->start_busy(1);
        return 1;
}
