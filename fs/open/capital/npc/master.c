// 書生公會老大 master.c by Onion
//change by adam 97/11/25
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string do_agree();

void create()
{
        set_name("楊書文", ({ "master yang", "yang", "master" }) );
        set("long",
        "楊書文是個面貌和藹的儒生﹐他在數十年前還是個尚書大人﹐不過後來決意高懸烏紗帽﹐"+
        "退出官場﹐如今已經不問政事﹐轉而研習武術之道﹐輕輕鬆鬆的過日子。\n");
        set("nickname", "春秋筆");
        set("gender", "男性" );
        set("age", 60);
        set("cor", 30);
        set("cps", 27);
        set("int", 24);

        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 3);

        set("rank_info/respect", "楊尚書");
        set("officer_class","退休大尚書");
        set("guild_master",1);
        set("class","scholar");
        set("title",HIW"書生公會榮譽會長"NOR);
        set("combat_exp",1000000);
        set_skill("dodge",60);
        set_skill("be-officer", 20);
        set_skill("force", 80);
        set_skill("magic", 20);
        set_skill("move", 60);
        set_skill("parry", 60);
        set_skill("unarmed",40);
        set_skill("literate",95);
  set_skill("spells",20);
   set_skill("cure",60);
        set("inquiry", ([
        "name" : "老夫便是當今書生之首﹐楊文書﹐尊敬我的呢﹐便稱我為楊尚書。",
        "here": "這裡便是書生公會。",
        "agree" : (: do_agree :),
        "書生工會":"你也想成為一名書生嗎?只要加入(join)就行了。",
        ]) );

        setup();
//      carry_object(CLASS_D("scholar")+"/obj/gold_pen")->wield();
}

void init()
{
        add_action("do_join","join");
}

int do_join(string str)
{
        object me=this_player();
        if(str!=0)
          return notify_fail("請打\"join\"即可。\n");
        if(me->query("class")=="scholar")
          return notify_fail("你已經是書生公會的一員了。\n");
        if(me->query("class")!=0)
          return notify_fail("你已經加入了別的工會了\n");
        me->set("class","scholar");
        write(HIC"楊書文和藹的對你說﹕從今後﹐你便是書生公會的一員了。\n"NOR);
        command("pat "+getuid(me));
        tell_object(users(),query("name")+HIC"長嘯道﹕歡迎"+me->query("name")+
        "加入書生公會。\n"NOR);
        return 1;
}
string do_agree()
{
        object me=this_player();
        if( me->query("class")!="scholar" )
          return("抱歉, 書房並不開放給非書生公會成員。\n");
        if( me->query("bellicosity") > 100 )
          return("抱歉, 你的殺氣太重, 我的書房不歡迎你這種人, 做些善事先。\n");
        me->set_temp("進入書房",1);
        return("歡迎..歡迎..你可以進入書房了。\n");
}

