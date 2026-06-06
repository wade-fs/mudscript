// beggar.c
// first written by grand 9/30/1995
// fixed by wade
// become guild master by Dico 07/10/1999

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("乞丐", ({ "beggar" }) );
        set("race", "人類");
        set("age", 23);
        set("long",@LONG
  一個渾身髒兮兮的乞丐，用乞求的眼光看著你。
你想起你是如此的殺孽罪重，不禁想幫他‧‧‧‧
你眼角的餘光看到他身上有八個小布袋，這似乎有
什麼重要的意義，但是你一時想不起來‧‧‧
LONG);
        set("str", 24);
        set("cor", 26);
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("max_force",3000);
        set("force",3000);
        set("max_kee",3000);
        set("kee",3000);
        set_skill("array",70);
        set_skill("move",60);
        set_skill("force",90);
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill("unarmed",120);
        set_skill("literate",30);

        set("chat_chance", 15);
        set("chat_msg", ({
                "乞丐用手拉了拉你袖子。\n",
                "乞丐抱住你的腳﹐想討東西吃。\n",
                "乞丐對著你喃喃自語。\n" }) );
        set("inquiry", ([
        "thief" : "給我一些錢, 我就偷偷說與你聽。",
        "袋子" : "老兄，眼力不錯嘛。既然你看到了那我就告訴你吧。\n現在丐幫熱烈招生中，想加入(JOIN)的話要趕快喔。",
        "小布袋" : "老兄，眼力不錯嘛。既然你看到了那我就告訴你吧。\n現在丐幫熱烈招生中，想加入(JOIN)的話要趕快喔。",
        "布袋" : "老兄，眼力不錯嘛。既然你看到了那我就告訴你吧。\n現在丐幫熱烈招生中，想加入(JOIN)的話要趕快喔。",
        ]));
        set("combat_exp",256);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
carry_object("/obj/cloth")->wear();
}

void reset()
{
  delete("accept_object");
}

// 用總次數故定對某些玩家不公, 會無法學到, 改成一人只給一次機會
// reset 的時候或者死掉重生的時候清掉重來, fixed by wade 12/13/1995
int accept_object(object who, object ob)
{
        int b, value;

        if (!query("accept_object/"+who->query("id"))) {
          b = who->query("bellicosity"); 
          if( (value=ob->value())  && b>0 ) {
                value = value/10;
                if (value < 1) value = 1;
                b = b - value;
                if (b < 0) b = 0;
                who->set("bellicosity", b); 
                add("accept_object/"+who->query("id"), 1);
                write("你覺得罪孽洗清了一些.\n");
          }
        }
        else
          say ("謝謝! 謝謝!\n");
        destruct(ob);
        return 1;
}

void init()
{
 add_action("do_join","join");
}

int do_join()
{
 if(this_player()->query("class"))
  return notify_fail("你已經加入其他公會了。\n");
 this_player()->set("class","beggar");
 message("system","\n你看見"+this_player()->name()+"把身上的衣服斯的破破爛爛的，\n"
 "把自己打扮的像一個乞丐一樣，真不曉得他腦袋裡在想什麼。\n\n",users());
 return 1;
}
