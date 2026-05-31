// 本程式首度尤 fund 撰寫
// 定搞於 wade
inherit F_SAVE;

mapping	quest_list;

void create()
{
  restore();
}

void remove(string euid) { save(); }

string query_save_file() { return QUEST; }

// 刪除一件任務
int delete_quest (string quest)
{
  // if (strsrch (quest, "quests/") == -1) quest = "quests/"+quest;
  // 從 quest_list 刪除一個 quest
  map_delete(quest_list, quest);

  save();
  return 1;
}

// 安裝一個 quest
int install_quest (string quest, string chinese)
{
  // if (strsrch (quest, "quests/") == -1) quest = "quests/"+quest;
  quest_list[quest] = chinese;

  if (save())
    return 1;
  else return 0;
}

// 傳回所有任務的英文字串
string *query_quests ()
{
  if (!undefinedp (keys(quest_list)))
    return keys(quest_list);
  else return ({});
}

//  用英文字串求中文名稱
string quest_chinese (string quest)
{
  if (strsrch (quest, "quests/") == -1) quest = "quests/"+quest;
  if ( !undefinedp(quest_list[quest]) )
    return quest_list[quest];
  else return "";
}

// 設定玩家已經完成某一個 quest 到第幾步
int set_quest (object ob, string quest, int step)
{
  if (!ob) return 0;
  // if (strsrch(quest, "quests/") == -1) quest = "quests/"+quest;
  ob->set_temp(quest, step);

  return 1;
}

// 查詢玩家已經完成某一個 quest 到第幾步
int query_quest (object ob, string quest)
{
  if (!ob) return 0;
  // if (strsrch(quest, "quests/") == -1) quest = "quests/"+quest;
  return (ob->query_temp (quest));
}

// 設定某玩家已經完成一個任務
int set_finish_quest (object ob, string quest)
{
  if (!ob) return 0;
  // if (strsrch(quest, "quests/") == -1) quest = "quests/"+quest;
  if (!ob->query(quest)) return 0;
  ob->add(quest, 1);
  return 1;
}

// 查詢是否完成一個任務
int query_finish_quest (object ob, string quest)
{
  if (!ob) return 0;
  // if (strsrch(quest, "quests/") == -1) quest = "quests/"+quest;
  if (quest_list[quest] == "") return 0;
  return (ob->query(quest));
}

// 用索引值取回中文任務名稱
string query_quest_cname (int idx)
{
  if (idx >= sizeof (quest_list)) return "";
  if (!undefinedp(quest_list)) return quest_list[keys(quest_list)[idx]];
  else return "";
}

// 用索引值取回英文任務名稱
string query_quest_name (int idx)
{
  if (idx >= sizeof (quest_list)) return "";
  if (!undefinedp(quest_list)) return keys(quest_list)[idx];
  else return "";
}

int query_quests_n ()
{
  return sizeof (quest_list);
}
