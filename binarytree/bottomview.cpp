
void dfs(TreeNode<int> *node, int col, int level, map<int, pair<int, int>> &bottomMap)
{
    if (!node)
        return;

    // For Bottom View: update if new column or deeper node found
    if (bottomMap.find(col) == bottomMap.end() || level >= bottomMap[col].second)
    {
        bottomMap[col] = {node->data, level};
    }

    dfs(node->left, col - 1, level + 1, bottomMap);
    dfs(node->right, col + 1, level + 1, bottomMap);
}

vector<int> getBottomView(TreeNode<int> *root)
{
    map<int, pair<int, int>> bottomMap; // col -> (value, level)
    dfs(root, 0, 0, bottomMap);

    vector<int> result;
    for (auto &[col, valLevelPair] : bottomMap)
    {
        int value = valLevelPair.first; // node's value
        result.push_back(value);
    }
    return result;
}