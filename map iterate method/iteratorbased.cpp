for (auto it = mp.begin(); it != mp.end(); ++it)
{
    int key = it->first;
    int val = it->second.first;
    int level = it->second.second;
    cout << key << " => " << val << ", " << level << endl;
}
