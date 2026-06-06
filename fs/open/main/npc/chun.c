// 延慶太子 by xboy
#include <ansi.h>
inherit NPC;

void create()
{
        set("long","
眼前這個老者，長鬚及胸，根根漆黑，一雙眼睜的大大的，望著遠方，
眨也不眨一下，臉色木然，似乎竟是死了一般，你彷彿感受到一股不祥
的預感，不禁打了個冷戰。\n");
        set("gender","男性");
        set("clan_kill",1);
        set("class","fighter");
        set("nickname",HIY + "惡貫滿盈" + NOR);
        set("title","四大惡人之首");
        set_name("段延慶",({"Duan ya-chun","duan","chun"}));
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("attitude","aggressive");
        set("max_force",5000);
        set("force",5000);
        set("max_kee",3000);
        set("kee",3000);
        set("max_gin",4000);
        set("max_sen",4000);
        set("sen",4000);
        set("gin",4000);
        set("str", 35);
        set("cor", 35);
        set("cps", 30);
        set("int", 30);
        set("force_factor",15);
        set_skill("dodge",100);
        set_skill("force",100);
        set_skill("parry",100);
        set_skill("six-fingers",100);
        set_skill("unarmed",40);
        set_skill("stabber",150);
        set_skill("literate",100);
        set_skill("sunforce",150);
        map_skill("force","sunforce");
        map_skill("unarmed","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("parry","six-fingers");
        set("functions/handwriting/level",20);
        set("chat_chance_combat", 15);
         set("chat_msg_combat", ({
                (: perform_action("six-fingers.handwriting") :),
        (: this_object(),"special_attack" :),
        }));

        setup();
        carry_object("/open/tailong/obj/i-staff")->wield();
        carry_object("/open/tailong/obj/i-staff")->wield();
        add_money("cash", 5);

}

 int special_attack()
 {
   object ob,me;
   int k;
   me = this_object();
   k = random(10);
   ob=this_object()->query_enemy();
   if(k > 7)
   {
   message_vision(HIG + "
\n\n段延慶口中逆運真氣, 突然大喝" + BLINK+HIR + "『狂" + HIC + "風" + HIG + "七" + HIM + "星" + HIW + "點』" + HIG + ", 只見手中" + HIB + "玄鐵仗換化成七道光芒,
 
向你疾奔而來, 你全身壟罩在無形劍氣之下, 進退維谷, 瞬時受到無法估計的傷害!!!!!\n\n" + NOR,this_object());
   ob->add("kee",-200);
   }
   else
   {
   message_vision(HIY + "\n
延慶太子雙手瘋狂亂點, 無數道劍氣, 織成一面耀眼劍網,此招正是段家的禁斷殺招

                        " + HIW + "～～" + HIM + " 無" + HIG + " 常" + HIW + " ～～

　　　　　　　　　　　　　　　　　～～" + HIR + " 恨" + NOR+CYN + " 蒼" + HIC + " 天" + HIW + " ～～

" + RED + "你深陷劍網當中, 首尾不能相顧, 頓時深中無數道劍氣, 只怕有身命危險!!!\n\n" + NOR,this_object());
ob->add("kee",-100);
me->add("kee",100);
   }
  return 1;
  }

void heart_beat()
{
 object me;
        if( random(5) < 4 ){
        if(!is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
            if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
                           }
        }
        :: heart_beat();
}

void die()
{
   object me,book;
   me= query_temp("last_damage_from");
        tell_object(users(),HIY + "

         延慶太子仰天嘆道：" + HIC + "『" + HIW + "老夫和大理段氏恩怨糾葛數十年
                             今日竟死在" + BLINK+HIY+me->query("name")+NOR+HIW + "之手，
                             難道是..天..在..譴..責..我..嗎......" + HIC + "』

" + NOR);

   if(me->query("marks/six_sp")<3 && !me->query("quest/4-badman"));
   {  
   me->set("marks/six_sp",2);
   me->set_temp("six_sp_quest",10);
   book=new("/open/tailong/obj/six_book");
   book->move(me);
   tell_object(me,
HIY + "你回想剛剛與延慶太子一戰，延慶太子的身形手法竟是如此巧妙
不禁暗暗僥倖自己居然能打敗他。\n"+
"你細想延慶太子戰鬥時的狂鬥神情，不由得自己比劃起來。\n"+
HIC + "你習得了禁斷殺招" + HIW + "『無常．恨蒼天』" + NOR + "!\n\n"+
"你自段延慶身上搜出" + HIY + "「六脈神劍劍經」" + NOR + "!\n"
);

   }
//  call_out("msg2",1,me);
   message_vision(HIG + "忽然一個白影以極快的速度一閃即過, 等你定睛一看, 白影早就已經消失, 段延慶也不見了!!\n" + NOR,this_object());
   destruct(this_object());
}

/*
void msg2(object me)
{
message("mud",HIR + "\n南海鱷神狂叫:你竟然殺了我們老大，老子今天要血洗平南城!!!\n" + NOR,me);
        ::die();

}
*/
