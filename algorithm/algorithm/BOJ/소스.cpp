
class bag {
private:
	int width, height, area;
	bag *childBag;
	bool hasParent;
public:
	bag(int width, int height)
	{
		this->width = width;
		this->height = height;
		this->area = width * height;
		this->childBag = NULL;
		this->hasParent = false;
	}

	void calcArea()
	{
		this->area = width * height;
	}

	void setWidth(int width)
	{
		this->width = width;
		calcArea();
	}

	void setHeight(int height)
	{
		this->height = height;
		calcArea();
	}

	void setChildBag(bag *ptrBag)
	{
		this->childBag = ptrBag;
	}

	void setHasParent(bool hasParent)
	{
		this->hasParent = hasParent;
	}

	int getWidth()
	{
		return width;
	}

	int getHeight()
	{
		return height;
	}

	int getArea()
	{
		return area;
	}

	bag *getChildBag()
	{
		return childBag;
	}

	bool getHasParent()
	{
		return hasParent;
	}

	bool operator<(bag& target)
	{
		return this->width < target.getWidth() &&
			this->height < target.getHeight();
	}

	bool operator>(bag& target)
	{
		return this->width > target.getWidth() &&
			this->height > target.getHeight();
	}
};

bool compareFunction(const pair<int, bag*>& x, const pair<int, bag*>& y) {
	return (x.first > y.first);
}

int solution(vector<vector<int>> map)
{
	int countLeftBag = map.size();
	vector<pair<int, bag*>> objectMap;

	for (auto k : map)
	{
		bag *ptrBag = new bag(k[0], k[1]);
		objectMap.push_back(pair<int, bag*>(ptrBag->getArea(), ptrBag));
	}

	sort(objectMap.begin(), objectMap.end(), compareFunction);

	for (int i = 0; i < objectMap.size(); i++)
	{
		bag *ptrPickedBag = objectMap[i].second;
		while (ptrPickedBag->getChildBag() != NULL) {
			ptrPickedBag = ptrPickedBag->getChildBag();
		}

		for (int j = i + 1; j < objectMap.size(); j++)
		{
			bag *ptrCheckingBag = objectMap[j].second;

			if (ptrCheckingBag->getHasParent())
			{
				continue;
			}

			if (*ptrPickedBag > *ptrCheckingBag)
			{
				ptrPickedBag->setChildBag(ptrCheckingBag);
				ptrCheckingBag->setHasParent(true);
				countLeftBag--;
			}
		}
	}

	return countLeftBag;
}
