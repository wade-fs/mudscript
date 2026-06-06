inherit NPC;

string *word1 = ({
  "王大媽", "李二嬸", "歸三娘", "林四姨", "乾媽", "舅媽",
  "四姨婆", "長舌婦",
});

string *word2 = ({
  "陳老頭", "丁大丙", "酸梅超人", "大雄", "怪醫秦博士", "阿甘",
});

string hname, wname;
string long();

void create()
{
	set_name("親戚",({"relative"}));
	set("long", (: long :) );
	set("no_kill",1);
	setup();
}

string long()
{
  object me=this_player();

  switch (random(3)) {
	case 0:
	  return word1[random(sizeof(word1))]+"\n";
	  break;
	case 1:
	  return word2[random(sizeof(word2))]+"\n";
	  break;
	case 2:
	  if (random(2))
	    return "新郎"+hname+"的親戚"+me->query("name")+"。\n";
	  else
	    return "新娘"+wname+"的親戚"+me->query("name")+"。\n";
  }
}

int start_marry(object husband, object wife)
{
  hname = husband->query("name");
  wname = wife->query("name");
} 
