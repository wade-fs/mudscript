inherit NPC;
void create()
{
        set_name("段正淳",({"duan zheng-chun","duan"}));
        set("gender","男性");
        set("age",45);
        set("class","scholar");
        set("str",40);
        set("long","帥氣的中年人 ,留有小鬍子 ,一付溫文儒雅的樣子 .\n");
        set("combat_exp",500000);
        set_skill("stabber",90);
        set_skill("force",70);
        set_skill("move",40);
        set("force",3000);
        set("max_force",3000);
        set("kee",2000);
        set("max_kee",2000);
          set_skill("literate",100);
        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("six-fingers",90);
        set_skill("linpo-steps",80);
        set_skill("sunforce",70);       
        map_skill("stabber","six-fingers");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("force","sunforce");
        set("force_factor",10);
        set("functions/handwriting/level",50);
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
        }));
        set("chat_chance",10);
        set("chat_msg",({
                "段正淳到處看來看去 ,神色甚是扭捏.\n",
                "段正淳說道 : 喔喔喔 !好想要女人喔 ,春宮畫也行啊 :~~\n"
                }));

        set("inquiry",([
        "莊靜柔" : "你說小柔柔啊 ,哼 ,一個小姑娘 ,竟敢拒絕我 ,我一定要找機會 ,把她
脫個精光然後就 .....\n",
        "進入" : "不要 !啥事都好商量 ,就這不行 ,這可是我一親小柔柔芳澤的大好良機 !\n",
        "想要女人嗎" : "想 ,想 :P~~~~~\n",
        ]));
        setup();
carry_object("/open/poison/obj/armband1.c")->wear();
set("family/family_name",8);
        add_money("gold",10);
}

int accept_object(object me,object ob)
{
  if(ob->query("id")=="playboy")
       {
        command("smile "+me->query("id"));
        if(me->query("gender")=="男性")
        command("say 小兄弟 ,真是謝謝你囉 !");
        if(me->query("gender")=="女性")
        command("say 小姑娘 ,妳 .....妳怎麼會有這種書 ,本王沒收 !");
        me->set_temp("playboy",1);
        command("say 為了報答你 ,本王讓你進去吧 !");
        tell_object(me,"快 !可以進去了 !\n");
        }
  return 1;
}

