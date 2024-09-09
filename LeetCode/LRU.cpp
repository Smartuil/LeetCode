#include "iostream"
#include "string"
#include "map"
#include "list"

template<typename KeyT, typename ValueT>
class LRUCache 
{
public:
	//�������
	typedef std::pair<KeyT, ValueT> Pair;
	typedef std::list<Pair> List;
	typedef std::map<KeyT, typename List::iterator> Map;

	//�вι��캯��
	explicit LRUCache(int cap);
	//��������
	~LRUCache();

	//��������
	bool put(KeyT key, ValueT value);
	//��ȡ����
	bool get(KeyT key, ValueT* pValue);

	//��ȡ�����С
	std::size_t size() const;

	//��ֹ�������캯��������
	LRUCache(const LRUCache&) = delete;
	//��ֹ������ֵ������������
	LRUCache& operator=(const LRUCache&) = delete;
private:
	int m_capacity;  //��ֵ������������ֵ����Ҫ����ĩβ��̭
	List m_list;     //����
	Map m_map;       //��ϣ��
};

template<typename KeyT, typename ValueT>
LRUCache<KeyT, ValueT>::LRUCache(int cap) : m_capacity(cap)
{
}

template<typename KeyT, typename ValueT>
LRUCache<KeyT, ValueT>::~LRUCache()
{
	m_list.clear();
	m_map.clear();
}

template<typename KeyT, typename ValueT>
std::size_t LRUCache<KeyT, ValueT>::size() const
{
	return m_list.size();
}

template<typename KeyT, typename ValueT>
bool LRUCache<KeyT, ValueT>::put(KeyT key, ValueT value)
{
	//����key�Ƿ��ڹ�ϣ��
	typename Map::iterator itor = m_map.find(key);
	//������ڣ���Ҫ�������ݴӹ�ϣ����������Ƴ�
	if (itor != m_map.end())
	{
		//��������ɾ��������
		m_list.erase(itor->second);
		//�ӹ�ϣ����ɾ��������
		m_map.erase(itor);
	}

	//���뵽�����ͷ
	m_list.push_front(std::make_pair(key, value));
	//����ͷ������ڵ��ŵ���ϣ��
	m_map[key] = m_list.begin();

	//�������С������ֵ��Ҫ����ĩβɾ��
	if (m_list.size() > m_capacity)
	{
		//��ȡ����ĩβ��keyֵ���Ա��ϣ����ɾ���ýڵ�
		KeyT endKey = m_list.back().first;
		//�Ƴ�����ĩβ�Ľڵ�
		m_list.pop_back();
		//�ӹ�ϣ����ɾ���ýڵ�
		m_map.erase(endKey);
	}

	return true;
}

template<typename KeyT, typename ValueT>
bool LRUCache<KeyT, ValueT>::get(KeyT key, ValueT* pValue)
{
	//����key�Ƿ��ڹ�ϣ��
	typename Map::iterator mapItor = m_map.find(key);
	//��������ڣ��򷵻�false
	if (mapItor == m_map.end())
	{
		return false;
	}

	//�������:
	//1.����Ҫ������ɾ��
	//2.Ȼ�������ݼ��뵽�����ͷ
	//Ŀ����Ϊ��ά�������ͷ��������ʵ�����

	//ȡ����ϣ���valueֵ��Ҳ��������ڵ�
	typename List::iterator listItor = mapItor->second;

	//�����µļ�ֵ��
	std::pair<KeyT, ValueT> listPair = std::make_pair(listItor->first, listItor->second);

	//������ɾ���ýڵ�
	m_list.erase(listItor);
	//�����ݼ��뵽��ͷ
	m_list.push_front(listPair);

	//���¹�ϣ��
	m_map[key] = m_list.begin();

	//ȡ������ڵ�����key-value��valueֵ��Ȼ��ֵ
	*pValue = listPair.second;

	return true;
}

int main()
{
	LRUCache<int, std::string> lruCache(3);

	lruCache.put(1, "A");
	lruCache.put(2, "B");
	lruCache.put(3, "C");

	std::string value;
	bool ret = true;

	ret = lruCache.get(1, &value);
	std::cout << "value = " << value << ", ret = " << ret << std::endl;

	lruCache.put(4, "D");

	value = "";
	ret = lruCache.get(2, &value);
	std::cout << "value = " << value << ", ret = " << ret << std::endl;

	return 0;
}