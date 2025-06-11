for (auto &[key, valPair] : mp)
{
    valPair.first += 10; // modifying value
    cout << key << " => " << valPair.first << ", " << valPair.second << endl;
}
