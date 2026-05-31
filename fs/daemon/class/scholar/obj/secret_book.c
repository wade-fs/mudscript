// by Onion.
//fixed by Lum 6/25/1996 修正非書生的人也能讀此書的Bug。
inherit ITEM;
string TITLE="[秘笈]";
string DESTRUCT_MESSAGE=TITLE+"這本秘笈不是你的,故書生工會會長楊書文派人將它取了回去。\n";
object me=this_player();
object ob=this_object();
mapping valid_types = ([
        "literate":     "讀書識字",
        "unarmed":      "拳腳",
        "sword":        "劍法",
        "blade":        "刀法",
        "stick":        "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
        "force":        "內功\",
        "parry":        "招架",
        "dodge":        "輕功\",
        "magic":        "法術",
         "spells":       "咒術",
        "move":         "行動",
        "array":        "陣法",
        "dagger":       "匕首",
        "cure":         "醫術",
        "plan":         "計謀",
        "stabber":      "刺術",
        "be-officer":   "政治",
        "whip":         "鞭法",
        "poison":       "用毒",
]);
 
void create()
{
      set_weight(0);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","本");
           set("long","這是一本記載武功\的秘笈, 通常只有書生之流的人才能憑著"+
           "優異的學識將本身的武功\心法計錄下來。\n"+
           "鍵入<help secret_book>可獲得更多的資訊。");
           set("value",0);
           set("no_drop",1);
           set("no_get",1);
           }
      set("belong",getuid(me));
      setup();
}
 
void init()
{
        set_name(me->name(1)+ "的武功\秘笈", ({ "secret_book" }));
        add_action("do_record","record");
        add_action("do_opento","opento");
        add_action("do_check","check");
        add_action("do_study","study");
        add_action("do_help","help");
}
int do_help(string str)
{
        if (str!="secret_book") return 0;
        write(@Help
 
        你可以使用以下的幾個命令:
        record <skill>          將本身武學記錄下來。
        opento <skill>          將書翻至記錄此技能的地方, 方便研讀。
        check secret_book       檢查書上所記載的技能。
        study secret_book       由書上研讀技能, 需先將書翻至正確的地方。
 
Help
        );
        return 1;
}
int do_study(string str)
{
        if( str != "secret_book" )              return 0;
        if( ob->query("skill/name") != 0 )      return 0;
        if( me->query("class")!= "scholar")
          return notify_fail(TITLE+"對於不是書生的人來說,這只是一本廢物。\n");
        if(me->query("id") != this_player()->query("id") ||
           ob->query("belong") != environment(this_object())->query("id"))
        {
          write(DESTRUCT_MESSAGE);
          destruct(ob);                         return 1;
        }
        write(TITLE+"秘笈還沒打開耶。\n");              return 1;
}
int do_record(string skill_name)
{
        int skill_max,skill_now;
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( skill_name == 0 )
          return notify_fail(TITLE+"記錄什麼?\n");
        skill_now=me->query_skill(skill_name,1);
        skill_max=me->query("secret_book/"+skill_name);
        if( skill_now <= 0 )
          return notify_fail(TITLE+"呵..你這項技能還沒練成勒。\n");
        if( me->query("class")!= "scholar")
          return notify_fail(TITLE+"對於不是書生的人來說,這只是一本廢物。\n");
        if( undefinedp(valid_types[skill_name]) )
          return notify_fail(TITLE+"你只能記錄基礎技能。\n");
        if( me->query_skill("literate",1) < skill_now )
          return notify_fail(TITLE+"你的學識不足, 無法將身上所學記錄下來。\n");
        if( skill_max >= skill_now )
          return notify_fail(TITLE+"你目前的技能並未比秘笈所記載的高出一級。\n");
        message_vision("$N在秘笈上龍飛鳳舞的寫下一些東西。\n",me);
        me->set("secret_book/"+skill_name,skill_now-1);
        if( me->query_skill("literate",1) < skill_now )
        {
          write(TITLE+"但由於你的學識不足, 無法將身上所學完全記錄下來。\n");
          me->set("secret_book/"+skill_name,me->query_skill("literate",1)-1);
        }
        return 1;
}
int do_opento(string skill_name)
{
        int max_skill=me->query("secret_book/"+skill_name);
        if( skill_name == 0 )
          return notify_fail(TITLE+"翻到那兒?\n");
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( me->query("secret_book/"+skill_name) == 0 )
          return notify_fail(TITLE+"秘笈中沒有提到這項技能。\n");
        ob->set("skill/name",skill_name);
        ob->set("skill/max_skill",max_skill);
        ob->set("skill/sen_cost",(max_skill/20)+20);
        ob->set("skill/difficulty",20);
        setup();
        write(TITLE+"你將秘笈展開至「"+to_chinese(skill_name)+"」處。\n");
        return 1;
}
int do_check(string str)
{
        int i;
        mapping secret_book_skill;
        string *skill_name;
        if( str != "secret_book" )
          return notify_fail(TITLE+"檢查什麼?\n");
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( sizeof(me->query("secret_book")) == 0 )
          return notify_fail(TITLE+"秘笈中目前仍是一片空白。\n");
        secret_book_skill=me->query("secret_book");
        skill_name=keys(secret_book_skill);
        write(TITLE+"以下是秘笈中記載的基本技能。\n");
        write("     名稱        等級\n");
        for(i=0; i<sizeof(skill_name); i++)
          printf(" %-10s       %3d\n",to_chinese(skill_name[i]),me->query("secret_book/"+skill_name[i]));
        return 1;
}
 
int query_autoload()
{
        if( this_player()->query("class")=="scholar" )
          return 1;
        return 0;
}
