inherit NPC;
string do_fb1();
string do_fb2();
string do_ans();
void create()
{
        set_name("皇柏壬",({"huang-bo ren","ren",}));
        set("gender","男性");
        set("age",60);
        set("str",45);
        set("bellicosity", 2000);
        set("title","猴王");
        set("long","曾是一代高手 ,因某種<原因>被魔教關來此地 ,百般無聊下習得操猴術 ,
便成為此地的猴王 !\n");
          set("combat_exp",700000);
        set("max_kee",1700);
        set("kee",1700);
        set("max_force",2000);
        set("force",2000);
        set_skill("unarmed",90);
        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("force",90);
        set_skill("badstrike",90);
        set_skill("black-steps",60);
        set_skill("badforce",80);
        map_skill("unarmed","badstrike");
        map_skill("parry","badstrike");
        map_skill("dodge","black-steps");
        map_skill("force","badforce");
        set("inquiry", ([
                "原因"  :  (: do_fb1() :),
                "伍元"  :  (: do_fb2() :),
                "老傢伙":  (: do_ans() :),
        ]));
        
        setup();
}

string do_fb1()
{
  object me=this_player();
  if(me->query_temp("quest-e")!=9)
  return("就是被關啦還問什麼原因");
  me->set_temp("findbook",1);
  return("哼, 說來話長, 想當初我可是魔教中最厲害的調蠱師呢...
          只怪那個臭傢伙, 明明就說要把那一位許\配給我
          卻被著我將那一位許\配給...那個人, <伍元>
          我不甘心啊~~臭<老傢伙>~~一想到你就一股氣啊~~");
}

string do_fb2()
{
  object me=this_player();
  if(me->query_temp("findbook")!=1)
  return("伍元??可以買乖乖喔");
  me->set_temp("findbook",2);
  return("就是當時的毒蠱長老嘛.....可恨當初他橫刀奪愛
          現在他不知道跑去哪裡躲起來了");
}

string do_ans()
{
  object me=this_player();
  return("就是前任教主, 嘿嘿, 因為我在他的練功\室中
          把毒蠱的比例調成顛倒了, 導致他氣血身亡
          莊靜柔那個笨女人還以為是伍元幹的, 還派人暗殺他
          只是算他命大, 逃過了這麼一劫...
          只是那一位居然偷偷密告是我幹的好事, 虧我對他一片情深...
          不過那一位也下場淒涼, 被放逐到外地");
        
}


