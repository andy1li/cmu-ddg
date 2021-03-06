## 1 Exterior Algebra in R<sup>n</sup>

### 1.1 Wedge product and k-vectors

**Exercise 1.** Let v = e<sub>1</sub> + 2e<sub>2</sub> and w = e<sub>2</sub> + 2e<sub>3</sub> be 1-vectors in R3 . Compute 

(a) v ∧ w = (e<sub>1</sub> + 2e<sub>2</sub>) ∧ (e<sub>2</sub> + 2e<sub>3</sub>) = e<sub>1</sub>∧e<sub>2</sub> + 2e<sub>1</sub>∧e<sub>3</sub> + 2e<sub>2</sub>∧e<sub>2</sub> + 4e<sub>2</sub>∧e<sub>3</sub> = e<sub>1</sub>∧e<sub>2</sub> + 2e<sub>1</sub>∧e<sub>3</sub> + 4e<sub>2</sub>∧e<sub>3</sub>.

(b) w ∧ v = (e<sub>2</sub> + 2e<sub>3</sub>) ∧ (e<sub>1</sub> + 2e<sub>2</sub>) = e<sub>2</sub>∧e<sub>1</sub> + 2e<sub>2</sub>∧e<sub>2</sub> + 2e<sub>3</sub>∧e<sub>1</sub> + 4e<sub>3</sub>∧e<sub>2</sub> =  e<sub>2</sub>∧e<sub>1</sub> + 2e<sub>3</sub>∧e<sub>1</sub> + 4e<sub>3</sub>∧e<sub>2</sub>.

(c) v ∧ v = (e<sub>1</sub> + 2e<sub>2</sub>) ∧ (e<sub>1</sub> + 2e<sub>2</sub>) = e<sub>1</sub>∧e<sub>1</sub> + 2e<sub>1</sub>e<sub>2</sub>  + 2e<sub>2</sub>∧e<sub>1</sub> + 4e<sub>2</sub>e<sub>2</sub> = 2e<sub>1</sub>e<sub>2</sub> - 2e<sub>1</sub>∧e<sub>2</sub> = 0.

**Exercise 2.** TODO

**Exercise 3.** TODO

**Exercise 4.** TODO 


---

### 1.2 Hodge Star

**Exercise 5.** (Hodge star in different dimensions.) 

(a) Assume we are working in R<sup>2</sup> , compute ★e<sub>1</sub> = e<sub>2</sub>.

(b) Assume we are working in R<sup>3</sup> , compute ★e<sub>1</sub> = e<sub>2</sub>∧e<sub>3</sub>.

(c) Why are the results of (a) and (b) different?

Since the Hodge star maps k-vectors to (n-k)-vectors, the grade of the result changes with the dimension of the underlying space.

---

**Exercise 6.** Let α = e<sub>1</sub> + e<sub>2</sub> + e<sub>3</sub>, β =  e<sub>1</sub> - e<sub>2</sub> + 2e<sub>3</sub>, be 1-vectors in R<sup>3</sup>. 

(a) Compute ★α = ★(e<sub>1</sub> + e<sub>2</sub> + e<sub>3</sub>) =  e<sub>2</sub>∧e<sub>3</sub> - e<sub>1</sub>∧e<sub>3</sub> + e<sub>1</sub>∧e<sub>2</sub>.

and ★β = ★(e<sub>1</sub> - e<sub>2</sub> + 2e<sub>3</sub>) =  e<sub>2</sub>∧e<sub>3</sub> + e<sub>1</sub>∧e<sub>3</sub> + 2e<sub>1</sub>∧e<sub>2</sub>.

(b) Compute ★(α ∧ β) = ★((e<sub>1</sub> + e<sub>2</sub> + e<sub>3</sub>) ∧ (e<sub>1</sub> - e<sub>2</sub> + 2e<sub>3</sub>)) 
= ★((e<sub>1</sub>∧e<sub>1</sub> - e<sub>1</sub>∧e<sub>2</sub> + 2e<sub>1</sub>∧e<sub>3</sub>) + (e<sub>2</sub>∧e<sub>1</sub> - e<sub>2</sub>∧e<sub>2</sub> + 2e<sub>2</sub>∧e<sub>3</sub>) + (e<sub>3</sub>∧e<sub>1</sub> - e<sub>3</sub>∧e<sub>2</sub> + 2e<sub>3</sub>∧e<sub>3</sub>))
= ★(- e<sub>1</sub>∧e<sub>2</sub> + 2e<sub>1</sub>∧e<sub>3</sub> - e<sub>1</sub>∧e<sub>2</sub> + 2e<sub>2</sub>∧e<sub>3</sub> - e<sub>1</sub>∧e<sub>3</sub> + e<sub>2</sub>∧e<sub>3</sub>)
= ★(- 2e<sub>1</sub>∧e<sub>2</sub> + e<sub>1</sub>∧e<sub>3</sub> + 3e<sub>2</sub>∧e<sub>3</sub>) = -2e<sub>3</sub> - e<sub>2</sub> + 3e<sub>1</sub>.

(c) Compute (★α) ∧ (★β) = ( e<sub>2</sub>∧e<sub>3</sub> - e<sub>1</sub>∧e<sub>3</sub> + e<sub>1</sub>∧e<sub>2</sub> ) ∧ (e<sub>2</sub>∧e<sub>3</sub> + e<sub>1</sub>∧e<sub>3</sub> + 2e<sub>1</sub>∧e<sub>2</sub>)
= (e<sub>2</sub>∧e<sub>3</sub>∧e<sub>2</sub>∧e<sub>3</sub> + e<sub>2</sub>∧e<sub>3</sub>∧e<sub>1</sub>∧e<sub>3</sub> + 2e<sub>2</sub>∧e<sub>3</sub>∧e<sub>1</sub>∧e<sub>2</sub>) - (e<sub>1</sub>∧e<sub>3</sub>∧e<sub>2</sub>∧e<sub>3</sub> + e<sub>1</sub>∧e<sub>3</sub>∧e<sub>1</sub>∧e<sub>3</sub> + 2e<sub>1</sub>∧e<sub>3</sub>∧e<sub>1</sub>∧e<sub>2</sub>) + (e<sub>1</sub>∧e<sub>2</sub>∧e<sub>2</sub>∧e<sub>3</sub> + e<sub>1</sub>∧e<sub>2</sub>∧e<sub>1</sub>∧e<sub>3</sub> + 2e<sub>1</sub>∧e<sub>2</sub>∧e<sub>1</sub>∧e<sub>2</sub>)
= 0.

(d) Why do (b) and (c) have different answers?



---

**Exercise 7.** (Applying the Hodge star twice.) Let w be any 1-vector in R<sup>n</sup> . 

(a) Show that if n = 2, then ★(★w) = −w. Can you explain why, geometrically? 

Let w = ae<sub>1</sub> + be<sub>2</sub>. ★(★w) = ★(★(ae<sub>1</sub> + be<sub>2</sub>)) = ★(ae<sub>2</sub> - be<sub>1</sub>) = - ae<sub>1</sub> - be<sub>2</sub> = -w.
Since taking ★ in  R<sup>2</sup> is a CW rotation, doing it twice results in a 180° rotation, the same as taking the nagative.

(b) Show that if n = 3, then ★(★w) = w. 

Let w = ae<sub>1</sub> + be<sub>2</sub> + ce<sub>3</sub>. ★(★w) = ★(★(ae<sub>1</sub> + be<sub>2</sub> + ce<sub>3</sub>)) 
= ★(ae<sub>2</sub>∧e<sub>3</sub> - be<sub>1</sub>∧e<sub>3</sub> + ce<sub>1</sub>∧e<sub>2</sub>) = ae<sub>1</sub> + be<sub>2</sub> + ce<sub>3</sub> = w.

(c) (Extra credit) Show for all n ≥ 2, that ★(★w) = (−1) n+1w. 

(d) (Extra credit) If w were a k-vector in R<sup>n</sup> , what can you say about ★(★w)?

---

**Exercise 8.** (Putting it all together.) 
In R<sup>3</sup>, let α = 2e<sub>3</sub> and β = e<sub>1</sub> − e<sub>2</sub> be 1-vectors, and let γ = e<sub>2</sub> ∧ e<sub>3</sub> be a 2-vector. 

(a) Compute α ∧ (β + ★γ). 

(b) Compute ★(γ ∧ ★(α ∧ β)).

---

## 2 Exterior Calculus in R<sup>n</sup>

## 3 Discrete Exterior Calculus

