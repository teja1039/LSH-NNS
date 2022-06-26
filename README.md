# LSH-NNS
Nearest Neighbour Search(NNS) using Locality Sensitive Hashing(LSH).
<br>
<p>We know that hashing allows one to store data in such a way that it is easy to search and is typically
efficient when the actual values are far less than the total possible values.</p>
<p>Locality Sensitive Hashing is a hashing technique that helps in NN-search queries. Herein, a family of
hashing functions H with the following property is chosen:</p>
<p>Given two points x and y and for any hashing function h ∈ H, the probability that h(x) = h(y) is high
only if x and y are close to each other. Thus given a query q, the bin to which q is hashed into by any h ∈ H is
likely to contain its nearest neighbour with high probability.</p>
<p>
  <b>Note:</b> 
  <ul>
    <li>The technique of determining the Voronoi partition or constructing K-d-trees or
      R-trees leads to deterministic NN search, while LSH is a stochastic NN search.</li>
    <li>LSH can be used for range queries, i.e., to find all the neighbours of q that are within a pre-specified distance.</li>
  </ul>
</p>
<p><b>Implemented:</b></p>
<ul>
  <li>Generated the set X ⊂ {0,1}<sup>d</sup> with n points, i.e., X consists of n binary vectors in d-dimensions.</li>
  <li>Determined a suitable family of hash functions H.</li>
  <li>Partitiond X based on these hashing bins.</li>
  <li>Implemented a nearest neighbour search for an arbitrary point q ∈ {0,1}<sup>d</sup> by choosing a hash function h from H uniformly at random, and returned the nearest neighbor of q from the bin it was mapped to.</li>
</ul>
### Team Members:
<ul>
  <li>Krishna Teja Chilukuri</li>
  <li>Nikhil Kongara</li>
  <li>Karthik Kurugodu</li>
</ul>
